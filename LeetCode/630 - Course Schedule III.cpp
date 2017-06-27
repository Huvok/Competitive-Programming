#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <functional>
#include <queue>
#include <bitset>
#include <sstream>
#include <set>
#include <iomanip>
#include <string.h>

using namespace std;

//															//AUTHOR: Hugo Garcia
//															//PURPOSE: Competitive programming template

//======================================================================================================================

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

//======================================================================================================================
class Solution 
{
public:
	int scheduleCourse(vector<vector<int>>& courses) 
	{
		//													//Just change to a vector of pairs because this way it is
		//													//		easier to understand.
		vector<pair<int, int>> v;

		for (int intI = 0; intI < courses.size(); intI++)
		{
			v.push_back(make_pair(courses[intI][1], courses[intI][0]));
		}

		int intTime = 0;
		priority_queue<int> pq;
		sort(v.begin(), v.end());

		for (int intI = 0; intI < v.size(); intI++)
		{
			if (intTime + v[intI].second <= v[intI].first)
			{
				intTime += v[intI].second;
				pq.push(v[intI].second);
			}
			else if (!pq.empty() &&
				pq.top() > v[intI].second)
			{
				intTime += (v[intI].second - (pq.top()));
				pq.pop();
				pq.push(v[intI].second);
			}
		}

		return pq.size();
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	Solution sol;
	vector<vector<int>> v = { {7, 17}, {3, 12}, {10, 20}, {9, 10}, {5, 20}, {10, 19}, {4, 18} };
	cout << sol.scheduleCourse(v) << endl;

	return 0;
}
//======================================================================================================================