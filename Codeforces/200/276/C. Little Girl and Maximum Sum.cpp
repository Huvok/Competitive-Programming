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
#define RFOR(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define pb push_back
#define mp make_pair
#define lld I64d
#define all(a) (a).begin(), (a).end()

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
ll arr[200005];
ll counts[200005];

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll intN, intQ;
	scanf("%lld %lld", &intN, &intQ);
	memset(counts, 0, sizeof(counts));
	FOR(intI, 0, intN) cin >> arr[intI];
	ll intL, intR;
	FOR(intI, 0, intQ)
	{
		scanf("%lld %lld", &intL, &intR);
		counts[intL - 1]++; counts[intR]--;
	}

	FOR(intI, 1, intN)
	{
		counts[intI] += counts[intI - 1];
	}

	sort(counts, counts + intN);
	sort(arr, arr + intN);

	ll intSum = 0;
	FOR(intI, 0, intN)
	{
		intSum += arr[intI] * counts[intI];
	}

	printf("%lld\n", intSum);

	return 0;
}

//======================================================================================================================