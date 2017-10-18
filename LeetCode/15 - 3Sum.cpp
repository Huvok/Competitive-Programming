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
	vector<vector<int>> threeSum(vector<int>& nums) 
	{
		sort(nums.begin(), nums.end());
		vector<vector<int>> v;
		FOR(intI, 0, nums.size() - 2)
		{
			if (!intI || (intI && nums[intI] != nums[intI - 1]))
			{
				ll intL = intI + 1;
				ll intH = nums.size() - 1;
				ll intTarget = nums[intI] * -1;
				while (intL < intH)
				{
					if (nums[intL] + nums[intH] == intTarget)
					{
						v.pb({ nums[intI], nums[intL], nums[intH] });
						while (intL < intH && nums[intL] == nums[intL + 1]) intL++;
						while (intL < intH && nums[intH] == nums[intH - 1]) intH--;
						intL++;
						intH--;
					}
					else if (nums[intL] + nums[intH] < intTarget)
					{
						intL++;
					}
					else
					{
						intH--;
					}
				}
			}
		}

		return v;
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	Solution sol;
	vector<int> v = { 0,0,0 };
	sol.threeSum(v);
	return 0;
}
//======================================================================================================================