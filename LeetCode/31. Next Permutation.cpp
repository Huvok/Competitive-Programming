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
#include <unordered_set>

using namespace std;

//															//AUTHOR: Hugo Garcia
//															//PURPOSE: Competitive programming template

//======================================================================================================================

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define pb push_back
#define mp make_pair
#define lld I64d

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
class Solution 
{
public:
	void reverse(ll i, vector<int>& nums)
	{
		ll j = nums.size() - 1;

		while (i < j)
		{
			swap(nums[i], nums[j]);
			i++;
			j--;
		}
	}

	void nextPermutation(vector<int>& nums) 
	{
		ll intIndex = -1;
		for (ll i = nums.size() - 2; i >= 0; i--)
		{
			if (nums[i] < nums[i + 1])
			{
				intIndex = i;
				break;
			}
		}

		if (intIndex != -1)
		{
			ll intToSwap = 0;
			ll intMin = 999999999999;
			FOR(intI, intIndex + 1, nums.size())
			{
				if (nums[intI] <= intMin &&
					nums[intI] > nums[intIndex])
				{
					intToSwap = intI;
					intMin = nums[intI];
				}
			}

			swap(nums[intIndex], nums[intToSwap]);
			reverse(intIndex + 1, nums);
		}
		else
		{
			reverse(0, nums);
		}
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{

	return 0;
}
//======================================================================================================================