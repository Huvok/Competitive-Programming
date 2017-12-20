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
ll AdjMat[2005][2005];
ll intV, intS, intF;
ll dist[2005];
bool included[2005];

ll minDistance()
{
	ll intMin = 1e15, idx;

	FOR(intJ, 0, intV)
	{
		if (included[intJ] == false &&
			dist[intJ] <= intMin)
		{
			intMin = dist[intJ];
			idx = intJ;
		}
	}

	return idx;
}

void dijkstra(ll intSrc)
{
	FOR(intI, 0, intV)
	{
		dist[intI] = 1e15;
		included[intI] = false;
	}

	dist[intSrc] = 0;

	FOR(intI, 0, intV - 1)
	{
		ll u = minDistance();

		included[u] = true;

		FOR(intJ, 0, intV)
		{
			if (!included[intJ] &&
				AdjMat[u][intJ] >= 0 &&
				dist[u] != 1e15 &&
				dist[u] + AdjMat[u][intJ] < dist[intJ])
			{
				dist[intJ] = dist[u] + AdjMat[u][intJ];
			}
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ifile("input.txt");
	ofile("output.txt");
	scanf("%lld %lld %lld", &intV, &intS, &intF);
	intS--; intF--;
	FOR(intI, 0, intV)
	{
		FOR(intJ, 0, intV)
		{
			scanf("%lld", &AdjMat[intI][intJ]);
		}
	}

	dijkstra(intS);

	cout << (dist[intF] == 1e15 ? -1 : dist[intF]) << endl;

	return 0;
}

//======================================================================================================================