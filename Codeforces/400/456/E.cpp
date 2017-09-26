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
ll diameter[300005];
vi AdjList[300005];
bool vis[300005];
ll intFurthestNode, intFurthestDiameter;

class UnionFind
{
private:
	vi p, size;

public:
	UnionFind(ll N)
	{
		size.assign(N, 1);
		p.assign(N, 0);

		for (ll i = 0; i < N; ++i)
		{
			p[i] = i;
		}
	}

	ll findSet(ll i)
	{
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}

	bool isSameSet(ll i, ll j)
	{
		return findSet(i) == findSet(j);
	}

	void unionSet(ll i, ll j)
	{
		ll x = findSet(i);
		ll y = findSet(j);
		if (size[x] > size[y]) swap(x, y);
		size[y] += size[x];
		p[x] = y;
	}

	ll rad(ll x)
	{
		return (diameter[x] + 1) / 2;
	}

	void unionSetMod(ll i, ll j)
	{
		if (!isSameSet(i, j))
		{
			ll x = findSet(i);
			ll y = findSet(j);
			if (size[x] > size[y]) swap(x, y);
			size[y] += size[x];
			p[x] = y;
			diameter[y] = max(rad(x) + rad(y) + 1, max(diameter[x], diameter[y]));
		}
	}
};

void dfs(ll intV, ll intDepth, ll intRoot)
{
	if (intDepth > intFurthestDiameter)
	{
		intFurthestDiameter = intDepth;
		intFurthestNode = intV;
	}

	FOR(intI, 0, AdjList[intV].size())
	{
		if (AdjList[intV][intI] != intRoot) dfs(AdjList[intV][intI], intDepth + 1, intV);
	}
}

ll intGetDiameter(ll intI)
{
	intFurthestDiameter = -1;
	dfs(intI, 0, -1);
	intFurthestDiameter = -1;
	dfs(intFurthestNode, 0, -1);
	return intFurthestDiameter;
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intM, intQ;
	scanf("%lld %lld %lld", &intN, &intM, &intQ);

	UnionFind uf(intN + 1);
	FOR(intI, 1, intN + 1)
	{
		diameter[intI] = 0;
	}

	ll intS, intD;
	FOR(intI, 1, intM + 1)
	{
		scanf("%lld %lld", &intS, &intD);
		AdjList[intS].pb(intD);
		AdjList[intD].pb(intS);
		uf.unionSet(intS, intD);
	}

	ll intCur;
	FOR(intI, 1, intN + 1)
	{
		intCur = uf.findSet(intI);
		if (!vis[intCur])
		{
			vis[intCur] = true;
			diameter[intCur] = intGetDiameter(intI);
		}
	}

	ll intType;
	while (intQ--)
	{
		scanf("%lld", &intType);
		if (intType == 1)
		{
			scanf("%lld", &intS);
			printf("%lld\n", diameter[uf.findSet(intS)]);
		}
		else
		{
			scanf("%lld %lld", &intS, &intD);
			uf.unionSetMod(intS, intD);
		}
	}

	return 0;
}
//======================================================================================================================