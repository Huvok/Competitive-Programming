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
bool h[200005], v[200005];
ii queries[200005];
ll intX1[200005], intX2[200005], intY1[200005], intY2[200005];
ll intAns[200005];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	memset(h, false, sizeof h);
	memset(v, false, sizeof v);
	ll intX, intY, intQ;

	scanf("%lld %lld %lld", &intX, &intY, &intQ);
	h[0] = true; h[intX] = true;
	v[0] = true; v[intY] = true;
	char c;
	ll intCut;
	FOR(intI, 0, intQ)
	{
		cin >> c >> intCut;

		if (c == 'V')
		{
			queries[intI] = mp(0, intCut);
			h[intCut] = true;
		}
		else
		{
			queries[intI] = mp(1, intCut);
			v[intCut] = true;
		}

	}

	ll intMaxH = 0, intMaxV = 0, intIndex = 0;

	FOR(intI, 1, intX)
	{
		if (h[intI])
		{
			intMaxH = max(intMaxH, intI - intIndex);
			intX1[intI] = intIndex;
			intX2[intIndex] = intI;
			intIndex = intI;
		}
	}

	intX1[intX] = intIndex;
	intX2[intIndex] = intX;
	intMaxH = max(intMaxH, intX - intIndex);

	intIndex = 0;
	FOR(intI, 1, intY)
	{
		if (v[intI])
		{
			intMaxV = max(intMaxV, intI - intIndex);
			intY1[intI] = intIndex;
			intY2[intIndex] = intI;
			intIndex = intI;
		}
	}

	intY1[intY] = intIndex;
	intY2[intIndex] = intY;
	intMaxV = max(intMaxV, intY - intIndex);

	for (ll intI = intQ - 1; intI >= 0; intI--)
	{
		intAns[intI] = 1LL * intMaxH * intMaxV;
		if (!queries[intI].first)
		{
			ll intL = intX1[queries[intI].second];
			ll intR = intX2[queries[intI].second];
			intMaxH = max(intMaxH, intR - intL);
			intX2[intL] = intR;
			intX1[intR] = intL;
		}
		else
		{
			ll intL = intY1[queries[intI].second];
			ll intR = intY2[queries[intI].second];
			intMaxV = max(intMaxV, intR - intL);
			intY2[intL] = intR;
			intY1[intR] = intL;
		}
	}

	FOR(intI, 0, intQ)
	{
		printf("%lld\n", intAns[intI]);
	}

	return 0;
}
//======================================================================================================================