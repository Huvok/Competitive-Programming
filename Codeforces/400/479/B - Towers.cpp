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
ll arr[105];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intK;
	scanf("%lld %lld", &intN, &intK);

	FOR(intI, 0, intN)
	{
		scanf("%lld", &arr[intI]);
	}
	ll intDif;
	priority_queue<ii> q;
	ll intMin = 90000000000, intMax = -500000000;
	FOR(intI, 0, intN)
	{
		intMin = min(intMin, arr[intI]);
		intMax = max(intMax, arr[intI]);
	}

	intDif = intMax - intMin;
	ll intCur = 0;
	vii ans;
	FOR(intI, 0, intK)
	{
		intMin = 0;
		intMax = 0;
		FOR(intJ, 0, intN)
		{
			if (arr[intJ] < arr[intMin])
			{
				intMin = intJ;
			}

			if (arr[intJ] > arr[intMax])
			{
				intMax = intJ;
			}
		}

		arr[intMax]--;
		arr[intMin]++;

		ll mi = intMin, ma = intMax;
		intMin = 90000000000;
		intMax = -5000000000;
		FOR(intI, 0, intN)
		{
			intMin = min(intMin, arr[intI]);
			intMax = max(intMax, arr[intI]);
		}

		ans.pb(mp(ma, mi));
		if (intMax - intMin < intDif)
		{
			intDif = intMax - intMin;
			intCur = intI + 1;
		}
	}

	printf("%lld %lld\n", intDif, intCur);
	FOR(intI, 0, intCur)
	{
		printf("%lld %lld\n", ans[intI].first + 1, ans[intI].second + 1);
	}

	return 0;
}
//======================================================================================================================