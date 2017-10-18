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

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll intN, intM;
	scanf("%lld %lld", &intN, &intM);

	ll intA, intB, intVal;
	vii v;
	FOR(intI, 0, intM)
	{
		scanf("%lld %lld %lld", &intA, &intB, &intVal);

		v.pb(mp(intA, intVal));
		v.pb(mp(intB + 1, -intVal));
	}

	ll intChamp = 0, intSum = 0;
	sort(v.begin(), v.end());
	FOR(intI, 0, intM * 2)
	{
		intSum += v[intI].second;
		intChamp = max(intChamp, intSum);
	}

	printf("%lld\n", intChamp);

	return 0;
}
//======================================================================================================================