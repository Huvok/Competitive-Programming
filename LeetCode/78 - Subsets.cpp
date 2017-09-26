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
#include <climits>
#include <unordered_map>

using namespace std;

//															//AUTHOR: Hugo Garcia
//															//PURPOSE: Competitive programming template

//======================================================================================================================

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
class Solution 
{
public:
	vector<vector<int>> subsets(vector<int>& nums)
	{
		vector<vector<int>> ss;

		FOR(intI, 0, pow(2, nums.size()))
		{
			vector<int> v;
			FOR(intJ, 0, nums.size())
			{
				if (intI & 1 << intJ)
				{
					v.pb(nums[intJ]);
				}
			}

			ss.pb(v);
		}

		return ss;
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	Solution sol;
	vector<int> v = { 1, 2, 3 };
	sol.subsets(v);
	return 0;
}
//======================================================================================================================