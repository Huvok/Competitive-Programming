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
ll mat[1505][1505];
vi taken;
ll intN;
priority_queue<pair<ll, ii>> pq;

struct node
{
	ll dist[1505];
};

struct tri
{
	ll v, u, w;
};

node nodes[1505];

vii AdjList[1505];

void process(ll v)
{
	ll orig = v;
	taken[v] = 1;
	FOR(j, 0, intN)
	{
		if (v == j) continue;
		ll i = mat[v][j];
		ii v = mp(j, i);
		if (!taken[v.first])
		{
			pq.push(mp(-v.second, ii(-v.first, -orig)));
		}
	}
}

bool vis[1505];
unordered_set<ll> bads;
void solve(ll i, ll cum)
{
	vis[i] = true;
	nodes[0].dist[i] = cum;

	FOR(j, 0, AdjList[i].size())
	{
		if (!vis[AdjList[i][j].first])
		{
			solve(AdjList[i][j].first, cum + AdjList[i][j].second);
		}
	}
}

void resolve(ll i, ll cost, ll from)
{
	vis[i] = true;
	FOR(j, 0, intN)
	{
		if (bads.find(j) != bads.end())
			nodes[i].dist[j] = nodes[from].dist[j] + cost;
		else
			nodes[i].dist[j] = nodes[from].dist[j] - cost;
	}

	nodes[i].dist[i] = 0;
	bads.insert(i);

	FOR(j, 0, AdjList[i].size())
	{
		if (!vis[AdjList[i][j].first])
		{
			resolve(AdjList[i][j].first, AdjList[i][j].second, i);
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ifile("input.txt");
	ofile("output.txt");
	scanf("%lld", &intN);

	FOR(i, 0, intN)
	{
		FOR(j, 0, intN)
		{
			scanf("%lld", &mat[i][j]);
		}
	}

	vector<tri> edges;
	taken.assign(intN, 0);
	process(0);
	while (!pq.empty())
	{
		pair<ll, ii> front = pq.top(); pq.pop();
		ll u = -front.second.first, w = -front.first, v = -front.second.second;
		if (!taken[u])
		{
			tri hue;
			hue.v = v; hue.u = u; hue.w = w;
			edges.pb(hue);
			process(u);
		}
	}

	FOR(i, 0, edges.size())
	{
		AdjList[edges[i].v].pb(mp(edges[i].u, edges[i].w));
		AdjList[edges[i].u].pb(mp(edges[i].v, edges[i].w));
	}

	memset(vis, false, sizeof(vis));
	solve(0, 0);
	memset(vis, false, sizeof(vis));
	resolve(0, 0, 0);

	bool bad = false;
	FOR(i, 0, intN)
	{
		FOR(j, 0, intN)
		{
			if (mat[i][j] < nodes[i].dist[j])
			{
				bad = true;
			}
		}
	}

	if (bad)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
		printf("%lld\n", edges.size());
		FOR(i, 0, edges.size())
		{
			printf("%lld %lld %lld\n", edges[i].v + 1, edges[i].u + 1, edges[i].w);
		}
	}

	return 0;
}

//======================================================================================================================