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
ll arr[100010], dp[100010];
ll intT, intN;

ll solve(ll intI)
{
	if (intI >= intN) return 0;
	if (dp[intI] != -1) return dp[intI];
	return dp[intI] = max(
		arr[intI] + solve(intI + 2),
		max(
			arr[intI] + (intI < intN - 1 ? arr[intI + 1] : 0) + solve(intI + 4),
			arr[intI] + (intI < intN - 1 ? arr[intI + 1] : 0) + (intI < intN - 2 ? arr[intI + 2] : 0) + solve(intI + 6)
		)
	);
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	scanf("%lld", &intT);

	while (intT--)
	{
		scanf("%lld", &intN);
		memset(dp, -1, sizeof(dp));
		FOR(intI, 0, intN)
		{
			scanf("%lld", &arr[intI]);
		}

		printf("%lld\n", solve(0));
	}

	return 0;
}
//======================================================================================================================