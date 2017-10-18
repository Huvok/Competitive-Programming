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
vi AdjList[205];
bool vis[205];

void dfs(ll i)
{
	vis[i] = true;

	FOR(intI, 0, AdjList[i].size())
	{
		if (!vis[AdjList[i][intI]])
		{
			dfs(AdjList[i][intI]);
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll intN, intM;

	scanf("%lld %lld", &intN, &intM);
	ll intNext, intE;
	ll intZeros = 1;
	FOR(intI, 1, intN + 1)
	{
		scanf("%lld", &intNext);
		if (intNext != 0) intZeros = 0;
		FOR(intJ, 0, intNext)
		{
			scanf("%lld", &intE);
			AdjList[intI].pb(intE + intM);
			AdjList[intE + intM].pb(intI);
		}
	}

	ll intCount = -1;
	memset(vis, false, sizeof(vis));
	FOR(intI, 1, intN + 1)
	{
		if (!vis[intI])
		{
			dfs(intI);
			intCount++;
		}
	}

	printf("%lld\n", intCount + intZeros);

	return 0;
}

//======================================================================================================================