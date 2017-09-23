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
class Solution {
public:
	bool checkPossibility(vector<int>& nums)
	{
		ll intCount = 0;
		FOR(intI, 1, nums.size())
		{
			if (intCount > 1) break;
			if (nums[intI - 1] > nums[intI])
			{
				intCount++;
				if (intI - 2 < 0 ||
					nums[intI - 2] <= nums[intI])
				{
					nums[intI - 1] = nums[intI];
				}
				else
				{
					nums[intI] = nums[intI - 1];
				}
			}
		}

		return intCount <= 1;
	}
};
//----------------------------------------------------------------------------------------------------------------------
int main()
{

	return 0;
}
//======================================================================================================================