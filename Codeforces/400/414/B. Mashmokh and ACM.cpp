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
vi divs[2005];
ll dp[2005][2005];

void sieve()
{
	FOR(i, 1, 2001)
	{
		for (ll j = i; j < 2001; j += i)
		{
			divs[j].pb(i);
		}
	}
}

void solve()
{
	FOR(i, 1, 2005)
	{
		dp[1][i] = 1;
	}

	FOR(i, 2, 2005)
	{
		FOR(j, 1, 2005)
		{
			FOR(k, 0, divs[j].size())
			{
				dp[i][j] += dp[i - 1][divs[j][k]];
				dp[i][j] %= 1000000007;
			}
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	sieve();
	ll n, k;
	cin >> n >> k;

	solve();

	ll ans = 0;
	FOR(i, 1, n + 1)
	{
		ans += dp[k][i];
		ans %= 1000000007;
	}

	cout << ans << endl;

	return 0;
}

//====================================================================================================================== 