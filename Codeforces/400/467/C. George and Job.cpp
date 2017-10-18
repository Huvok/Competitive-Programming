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
ll dp[5005][5005];
ll arr[5005];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intM, intK;
	cin >> intN >> intM >> intK;
	memset(dp, 0, sizeof(dp));
	memset(arr, 0, sizeof(arr));
	FOR(intI, 1, intN + 1)
	{
		cin >> arr[intI];
		if (intI) arr[intI] += arr[intI - 1];
	}

	FOR(intI, 1, intK + 1)
	{
		FOR(intJ, intI * intM, intN + 1)
		{
			dp[intI][intJ] = max(dp[intI][intJ - 1], dp[intI - 1][intJ - intM] + arr[intJ] - arr[intJ - intM]);
		}
	}

	cout << dp[intK][intN] << endl;

	return 0;
}

//======================================================================================================================