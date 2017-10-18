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
ll AdjList[405][405];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intV, intE, intQ;
	scanf("%lld %lld", &intV, &intE);

	FOR(intI, 0, 405)
	{
		FOR(intJ, 0, 405)
		{
			AdjList[intI][intJ] = 9999999999999;
		}

		AdjList[intI][intI] = 0;
	}
	ll intS, intD, intW;
	FOR(intI, 0, intE)
	{
		scanf("%lld %lld %lld", &intS, &intD, &intW);

		AdjList[intS][intD] = intW;
	}

	FOR(intK, 1, intV + 1)
	{
		FOR(intI, 1, intV + 1)
		{
			FOR(intJ, 1, intV + 1)
			{
				AdjList[intI][intJ] = min(AdjList[intI][intJ], AdjList[intI][intK] + AdjList[intK][intJ]);
			}
		}
	}

	scanf("%lld", &intQ);

	FOR(intI, 0, intQ)
	{
		scanf("%lld %lld", &intS, &intD);
		printf("%lld\n", AdjList[intS][intD] != 9999999999999 ? AdjList[intS][intD] : -1);
	}

	return 0;
}
//======================================================================================================================