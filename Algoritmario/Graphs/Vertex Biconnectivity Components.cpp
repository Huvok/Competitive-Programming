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
#include <limits.h>

using namespace std;

//															//AUTHOR: Hugo Garcia
//															//PURPOSE: Competitive programming template

//======================================================================================================================

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define RFOR(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define pb push_back
#define mp make_pair
#define lld I64d
#define all(a) (a).begin(), (a).end()
#define ifile(a) freopen((a), "r", stdin)
#define ofile(a) freopen((a), "w", stdout)
#define sync ios_base::sync_with_stdio(false)

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

using namespace std;

//----------------------------------------------------------------------------------------------------------------------
ll intV, intE;
vi AdjList[200005];
bool vis[200005];
ll disc[200005], low[200005], parent[200005];
vii edges;
stack<ii> s;
ll cur = 0;
ll intCount = 0;
unordered_map<ll, ll> lst[200005];
ll ans[200005];

void solve(ll u)
{
	disc[u] = low[u] = ++cur;
	ll ch = 0;

	FOR(intI, 0, AdjList[u].size())
	{
		ll v = AdjList[u][intI];

		if (disc[v] == -1)
		{
			ch++;
			parent[v] = u;

			s.push(mp(u, v));
			solve(v);

			if (low[u] > low[v])
				low[u] = low[v];

			if ((disc[u] == 1 && ch > 1) ||
				(disc[u] > 1 && low[v] >= disc[u]))
			{
				while (s.top().first != u || s.top().second != v)
				{
					lst[s.top().first][s.top().second] = intCount + 1;
					lst[s.top().second][s.top().first] = intCount + 1;
					//cout << s.top().first << "--" << s.top().second << " ";
					s.pop();
				}

				lst[s.top().first][s.top().second] = intCount + 1;
				lst[s.top().second][s.top().first] = intCount + 1;
				//cout << s.top().first << "--" << s.top().second << " ";
				//cout << endl;
				s.pop();

				intCount++;
			}
		}
		else if (v != parent[u] && disc[v] < low[u])
		{
			if (low[u] > disc[v])
				low[u] = disc[v];
			s.push(mp(u, v));
		}
		else if (lst[u][v] == 0)
		{
			s.push(mp(u, v));
		}
	}
}

void dfs()
{
	FOR(intI, 1, intV + 1)
	{
		disc[intI] = low[intI] = parent[intI] = -1;
	}

	FOR(intI, 1, intV + 1)
	{
		if (disc[intI] == -1)
		{
			solve(intI);
		}

		ll intJ = 0;

		while (!s.empty())
		{
			intJ = 1;
			lst[s.top().first][s.top().second] = intCount + 1;
			lst[s.top().second][s.top().first] = intCount + 1;
			//cout << s.top().first << "--" << s.top().second << " ";
			s.pop();
		}

		if (intJ == 1)
		{
			//cout << endl;
			intCount++;
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ifile("input.txt");
	ofile("output.txt");
	scanf("%lld %lld", &intV, &intE);

	ll intS, intD;
	FOR(intI, 0, intE)
	{
		scanf("%lld %lld", &intS, &intD);

		AdjList[intS].pb(intD);
		AdjList[intD].pb(intS);
		edges.pb(mp(intS, intD));
	}

	FOR(intI, 1, intV + 1)
	{
		FOR(intJ, 0, AdjList[intI].size())
		{
			lst[intI].insert(mp(AdjList[intI][intJ], 0));
		}
	}

	memset(vis, false, sizeof(vis));

	dfs();

	FOR(intI, 0, intE)
	{
		ans[intI] = lst[edges[intI].first][edges[intI].second];
	}

	printf("%lld\n", intCount);

	FOR(intI, 0, intE)
	{
		printf("%lld ", ans[intI]);
	}

	printf("\n");
	

	return 0;
}

//======================================================================================================================