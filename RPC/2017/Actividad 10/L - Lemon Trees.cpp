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
ll arr[100005];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intK;

	while (scanf("%lld %lld", &intN, &intK) == 2)
	{
		ll intH = 0;
		FOR(intI, 0, intN)
		{
			scanf("%lld", &arr[intI]);
			intH += arr[intI];
		}

		ll intL = 0;
		while (intL < intH)
		{
			ll intMiddle = ((intH - intL) >> 1) + intL;
			ll intLeft = intK;
			ll intSum = 0;
			FOR(intI, 0, intN)
			{
				if (intLeft <= 0) break;
				if (intMiddle >= intSum + arr[intI])
				{
					intSum += arr[intI];
				}
				else
				{
					intLeft--;
					intSum = 0;
					intI--;
				}
			}

			if (intLeft > 0)
			{
				intH = intMiddle;
			}
			else
			{
				intL = intMiddle + 1;
			}
		}

		printf("%lld\n", intL);
	}

	return 0;
}
//======================================================================================================================