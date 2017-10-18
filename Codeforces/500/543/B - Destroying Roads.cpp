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
ll dp[3005][3005];
vi AdjList[3005];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	memset(dp, -1, sizeof(dp));
	ll intV, intE;
	scanf("%lld %lld", &intV, &intE);

	ll intS, intD;
	FOR(intI, 0, intE)
	{
		scanf("%lld %lld", &intS, &intD);
		AdjList[intS - 1].pb(intD - 1);
		AdjList[intD - 1].pb(intS - 1);
	}

	FOR(intI, 0, intV) dp[intI][intI] = 0;

	FOR(intI, 0, intV)
	{
		queue<ll> q;
		q.push(intI);

		while (!q.empty())
		{
			ll intCur = q.front();
			q.pop();

			FOR(intJ, 0, AdjList[intCur].size())
			{
				if (dp[intI][AdjList[intCur][intJ]] == -1)
				{
					dp[intI][AdjList[intCur][intJ]] = dp[intI][intCur] + 1;
					q.push(AdjList[intCur][intJ]);
				}
			}
		}
	}

	ll intS0, intS1, intT0, intT1, intL0, intL1;
	scanf("%lld %lld %lld", &intS0, &intT0, &intL0);
	scanf("%lld %lld %lld", &intS1, &intT1, &intL1);
	intS0--; intS1--; intT0--; intT1--;

	ll intChamp = intE + 1;
	FOR(intI, 0, 2)
	{
		ll intAux = intS0;
		intS0 = intT0;
		intT0 = intAux;

		FOR(intJ, 0, intV)
		{
			FOR(intK, 0, intV)
			{
				if (dp[intS0][intJ] + dp[intJ][intK] + dp[intK][intT0] <= intL0 &&
					dp[intS1][intJ] + dp[intJ][intK] + dp[intK][intT1] <= intL1)
				{
					intChamp = min(intChamp, dp[intS0][intJ] + dp[intJ][intK] + dp[intK][intT0] +
						dp[intS1][intJ] + dp[intJ][intK] + dp[intK][intT1] - dp[intJ][intK]);
				}
			}
		}
	}

	if (dp[intS0][intT0] <= intL0 &&
		dp[intS1][intT1] <= intL1)
	{
		intChamp = min(intChamp, dp[intS0][intT0] + dp[intS1][intT1]);
	}

	printf("%lld\n", intChamp > intE ? -1 : intE - intChamp);

	return 0;
}
//======================================================================================================================