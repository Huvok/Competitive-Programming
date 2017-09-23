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
ll arr[1005], rra[1005];

ll LIS(ll intI, ll intJ, ll intMode)
{
	vi v;
	FOR(i, intI, intJ + 1)
	{
		auto it = lower_bound(v.begin(), v.end(), intMode == 0 ? arr[i] : rra[i]);
		if (it - v.begin() >= v.size())
		{
			v.pb(intMode == 0 ? arr[i] : rra[i]);
		}
		else
		{
			v[it - v.begin()] = intMode == 0 ? arr[i] : rra[i];
		}
	}

	return v.size();
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intT, intN;
	scanf("%lld", &intT);

	while (intT--)
	{
		scanf("%lld", &intN);

		FOR(intI, 0, intN)
		{
			scanf("%lld", &arr[intI]);
			rra[intI] = -1 * arr[intI];
		}

		ll intChamp = 0;
		FOR(intI, 0, intN)
		{
			if (!intI)
			{
				intChamp = max(intChamp, LIS(0, intN - 1, 1));
			}
			else if (intI == intN - 1)
			{
				intChamp = max(intChamp, LIS(0, intN - 1, 0));
			}
			else
			{
				intChamp = max(intChamp, LIS(0, intI, 0) + LIS(intI, intN - 1, 1) - 1);
			}
		}

		printf("%lld\n", intChamp);
	}

	return 0;
}
//======================================================================================================================