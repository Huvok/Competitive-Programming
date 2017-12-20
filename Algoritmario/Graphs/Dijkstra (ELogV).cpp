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
ll intV, intE, intS, intD, intW;
vii AdjList[30005];
ll dist[30005];

void dijkstra(ll intSrc)
{
	priority_queue<ii, vii, greater<ii>> pq;
	FOR(intI, 1, intV + 1) dist[intI] = INT_MAX;
	pq.push(mp(0, intSrc));
	dist[intSrc] = 0;

	while (!pq.empty())
	{
		ll u = pq.top().second;
		pq.pop();

		FOR(intI, 0, AdjList[u].size())
		{
			ll v = AdjList[u][intI].first;
			ll w = AdjList[u][intI].second;

			if (dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				pq.push(mp(dist[v], v));
			}
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	scanf("%lld %lld", &intV, &intE);

	FOR(intI, 0, intE)
	{
		scanf("%lld %lld %lld", &intS, &intD, &intW);
		AdjList[intS].pb(mp(intD, intW));
		AdjList[intD].pb(mp(intS, intW));
	}

	dijkstra(1);

	FOR(intI, 1, intV + 1)
	{
		printf("%lld ", dist[intI]);
	}

	printf("\n");

	return 0;
}

//======================================================================================================================