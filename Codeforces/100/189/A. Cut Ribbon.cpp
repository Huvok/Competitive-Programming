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
ll intN, a, b, c;
ll dp[4005];

ll solve(ll n)
{
	if (n == 0) return 0;
	if (n < 0 || (n > 0 && n < a && n < b && n < c)) return -INT_MAX;
	if (dp[n] == -1) dp[n] = max(solve(n - a), max(solve(n - b), solve(n - c))) + 1;
	return dp[n];
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	cin >> intN >> a >> b >> c;
	FOR(intI, 0, intN + 1) dp[intI] = -1;
	cout << solve(intN) << endl;

	return 0;
}

//======================================================================================================================