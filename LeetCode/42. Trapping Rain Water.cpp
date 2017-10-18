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
	int trap(vector<int>& height) 
	{
		ll l = 0, r = height.size() - 1;
		ll intRet = 0;
		ll intLMax = 0, intRMax = 0;

		while (l < r)
		{
			if (height[l] < height[r])
			{
				if (height[l] >= intLMax)
				{
					intLMax = height[l];
				}
				else
				{
					intRet += (intLMax - height[l]);
				}

				l++;
			}
			else
			{
				if (height[r] >= intRMax)
				{
					intRMax = height[r];
				}
				else
				{
					intRet += (intRMax - height[r]);
				}

				r--;
			}
		}

		return intRet;
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{

	return 0;
}
//======================================================================================================================