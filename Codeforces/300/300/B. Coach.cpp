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
#define RFOR(i, a, b) for(ll i=ll(a) - 1; i>=ll(b); i--)
#define pb push_back
#define mp make_pair
#define lld I64d
#define all(a) (a).begin(), (a).end()

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
vi AdjList[55];
vi ans[55];
vi cur;
ll intSize;
bool vis[55];

void dfs(ll i)
{
	intSize++;
	cur.pb(i);
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
	cin >> intN >> intM;

	ll intS, intD;
	FOR(intI, 0, intM)
	{
		cin >> intS >> intD;
		AdjList[intS].pb(intD);
		AdjList[intD].pb(intS);
	}

	memset(vis, false, sizeof(vis));

	FOR(intI, 1, intN + 1)
	{
		intSize = 0;
		cur.clear();
		if (vis[intI] == false) dfs(intI);

		FOR(intI, 0, cur.size())
		{
			ans[intSize].pb(cur[intI]);
		}
	}

	FOR(intI, 4, 55)
	{
		if (ans[intI].size() > 0)
		{
			cout << -1 << endl;
			return 0;
		}
	}

	if (ans[2].size() > 2 * ans[1].size())
	{
		cout << -1 << endl;
	}
	else
	{
		FOR(intI, 0, ans[3].size())
		{
			if (intI && intI % 3 == 0) cout << endl;
			cout << ans[3][intI] << " ";
		}

		ll intCur = 0;
		FOR(intI, 0, ans[2].size())
		{
			if (intI && intI % 2 == 0)
			{
				cout << ans[1][intCur++] << endl;
			}
			cout << ans[2][intI] << " ";
		}

		ll intCount = 0;
		FOR(intI, intCur, ans[1].size())
		{
			if (intCount && intCount % 3 == 0) cout << endl;
			cout << ans[1][intI] << " ";
		}

		cout << endl;
	}

	return 0;
}

//======================================================================================================================