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
	int findKthNumber(int m, int n, int k) 
	{
		ll intL = 0, intH = m * n, intMiddle;
		while (intL < intH)
		{
			intMiddle = ((intH - intL) >> 2) + intL;
			ll intCount = 0;
			FOR(intI, 1, m + 1)
			{
				intCount += min(intMiddle / intI, (ll)n);
			}

			if (intCount >= k)
			{
				intH = intMiddle;
			}
			else
			{
				intL = intMiddle + 1;
			}
		}

		return intL;
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	
	return 0;
}
//======================================================================================================================