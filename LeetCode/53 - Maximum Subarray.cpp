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
#include <unordered_map>

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
	int maxSubArray(vector<int>& nums) 
	{
		long long intSum = -2147483647;
		long long intChamp = -2147483647;

		for (int intI = 0; intI < nums.size(); intI++)
		{
			intSum = max(intSum + nums[intI], (long long)nums[intI]);
			intChamp = max(intChamp, intSum);
		}

		return intChamp;
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	Solution s;
	vector<int> v;
	v.push_back(-2147483647);
	cout << s.maxSubArray(v);
	return 0;
}
//======================================================================================================================