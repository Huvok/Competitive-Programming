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
ll dp[100005];
ll travel[100005];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN;
	scanf("%lld", &intN);

	dp[0] = 0; dp[1] = 20;
	FOR(intI, 0, intN)
	{
		scanf("%lld", &travel[intI]);
	}

	FOR(intI, 0, intN)
	{
		ll travelMinus90 = upper_bound(travel, travel + intN, travel[intI] - 90) - travel;
		ll travelMinus120 = upper_bound(travel, travel + intN, travel[intI] - 1440) - travel;
		dp[intI + 1] = min(dp[intI] + 20, min(dp[travelMinus90] + 50, dp[travelMinus120] + 120));
	}

	FOR(intI, 1, intN + 1)
	{
		printf("%lld\n", dp[intI] - dp[intI - 1]);
	}

	return 0;
}

//======================================================================================================================