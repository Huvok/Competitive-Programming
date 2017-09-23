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
vi AdjList[15];
ll arr[15];
bool vis[15];
set<ll> s;

void dfs(ll i)
{
	vis[i] = true;
	vi v;
	FOR(intI, 0, AdjList[i].size())
	{
		if (arr[AdjList[i][intI]] != -1)
		{
			v.pb(arr[AdjList[i][intI]]);
		}
	}

	sort(v.begin(), v.end());
	ll intBest = 0;
	FOR(intI, 0, v.size())
	{
		if (v[intI] == intBest) intBest++;
		else break;
	}

	arr[i] = intBest;

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
	ll intV, intE, intNext;

	while (scanf("%lld", &intV) == 1)
	{
		s.clear();
		FOR(intI, 0, intV) AdjList[intI].clear();
		FOR(intI, 0, intV)
		{
			scanf("%lld", &intE);

			FOR(intJ, 0, intE)
			{
				scanf("%lld", &intNext);
				intNext--;
				AdjList[intI].pb(intNext);
			}
		}

		memset(arr, -1, sizeof(arr));
		memset(vis, false, sizeof(vis));
		FOR(intI, 0, intV)
		{
			if (!vis[intI]) dfs(intI);
		}

		FOR(intI, 0, intV)
		{
			if (arr[intI] != -1 &&
				s.find(arr[intI]) == s.end())
			{
				s.insert(arr[intI]);
			}
		}

		printf("%lld\n", s.size());
	}

	return 0;
}
//======================================================================================================================