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
vii AdjList[50005];
ll intChamp;
ll d[50005];

struct edge {
	ll to, w;
	edge(ll f, ll we) { to = f; w = we; }
	bool operator <(const edge& a) const {
		return w > a.w;
	}
};

void dijkstra(ll from, ll to) {
	FOR(i, 0, 50006) d[i] = 99999999999999LL;
	d[from] = 0;
	intChamp = 0;
	priority_queue<edge> pq;
	pq.push(edge(from, 0));

	while (!pq.empty()) {
		edge act = pq.top();
		pq.pop();
		FOR(i, 0, AdjList[act.to].size())
		{
			if (max(d[act.to], AdjList[act.to][i].second) < d[AdjList[act.to][i].first])
			{
				d[AdjList[act.to][i].first] = max(d[act.to], AdjList[act.to][i].second);
				pq.push(edge(AdjList[act.to][i].first, d[AdjList[act.to][i].first]));
			}
		}
	}
}
//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll intV, intE;
	scanf("%lld %lld", &intV, &intE);
	ll intS, intD, intW;
	FOR(intI, 0, intE)
	{
		scanf("%lld %lld %lld", &intS, &intD, &intW);
		AdjList[intS].pb(mp(intD, intW));
		AdjList[intD].pb(mp(intS, intW));
	}

	dijkstra(1, intV);

	if (d[intV] != 99999999999999LL)
	{
		printf("%lld\n", d[intV]);
	}
	else
	{
		printf("NO PATH EXISTS\n");
	}


	return 0;
}
//======================================================================================================================