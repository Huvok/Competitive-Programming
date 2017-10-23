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
ll arr[100005];
ll dp[100005];
ll counts[100005];

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll intN;
	cin >> intN;

	FOR(intI, 0, intN) cin >> arr[intI];
	memset(counts, 0, sizeof(counts));
	ll intMax = 0;
	FOR(intI, 0, intN)
	{
		counts[arr[intI]]++;
		intMax = max(intMax, arr[intI]);
	}

	dp[0] = 0;
	dp[1] = counts[1];

	FOR(intI, 2, intMax + 1)
	{
		dp[intI] = max(dp[intI - 2] + counts[intI] * intI, dp[intI - 1]);
	}

	cout << dp[intMax] << endl;

	return 0;
}

//======================================================================================================================