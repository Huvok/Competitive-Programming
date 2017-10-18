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
	int removeDuplicates(vector<int>& nums)
	{
		if (nums.size() == 0) return 0;
		ll intCur = 0;
		FOR(intI, 1, nums.size())
		{
			if (nums[intCur] != nums[intI])
			{
				intCur++;
				nums[intCur] = nums[intI];
			}
		}

		return intCur + 1;
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{

	return 0;
}
//======================================================================================================================