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
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//======================================================================================================================
class Solution {
public:
	int arr[105];

	vector<int> exclusiveTime(int n, vector<string>& logs)
	{
		memset(arr, 0, sizeof(arr));

		stack<pair<int, int>> s;
		stack<int> lastTime;

		for (int i = 0; i < logs.size(); i++)
		{
			string str = "";
			int j = 0;
			for (; j < logs[i].length(); j++)
			{
				if (logs[i][j] == ':') break;
				else str += logs[i][j];
			}

			int intLog = atoi(str.c_str());
			j++;

			str = "";
			for (; j < logs[i].length(); j++)
			{
				if (logs[i][j] == ':') break;
				else str += logs[i][j];
			}

			char c;
			if (str[0] == 's')
			{
				c = 's';
			}
			else c = 'e';
			j++;

			str = "";
			for (; j < logs[i].length(); j++)
			{
				str += logs[i][j];
			}

			int intTime = atoi(str.c_str());
			if (c == 's')
			{
				s.push(make_pair(intLog, intTime));
				lastTime.push(0);
			}
			else
			{
				arr[intLog] += intTime - s.top().second + 1;
				int time = s.top().second;
				s.pop();

				if (!s.empty())
					arr[s.top().first] -= intTime - time + 1;
			}
		}

		vector<int> v;
		for (int i = 0; i < n; i++)
		{
			v.push_back(arr[i]);
		}

		return v;
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	Solution s;
	/*vector<string> v = { "0:start:0",
		"1:start:2",
		"1:end:5",
		"0:end:6" };*/

	vector<string> v = { "0:start:0", "0:start:2", "0:end:5", "0:start:6", "0:end:6", "0:end:7" };

	//vector<string> v = { "0:start:0", "0:start:2", "0:end:5", "1:start:7", "1:end:7", "0:end:8" };

	//vector <string> v = { "0:start:0","0:start:1","0:start:2","0:end:3","0:end:4","0:end:5" };

	vector<int> vec = s.exclusiveTime(1, v);
	return 0;
}
//======================================================================================================================