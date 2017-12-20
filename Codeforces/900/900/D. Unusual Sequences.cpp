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
#define MOD 1000000007
unordered_map<ll, ll> dp;

ll fastPow(ll x, ll n) 
{
	ll ret = 1;
	while (n) 
	{
		if (n & 1) ret = ret = ret * x % MOD;
		x = x * x % MOD;
		n >>= 1;
	}

	return ret;
}

vi getDiv(ll i)
{
	vi divisors;
	divisors.reserve(sqrt(i));
	for (ll cur = 1; cur * cur <= i; cur++)
	{
		if (i % cur == 0)
		{
			if (cur != 1)
				divisors.pb(cur);

			if (i / cur != cur)
				divisors.pb(i / cur);
		}
	}

	return divisors;
}

ll f(ll i)
{
	if (dp.find(i) != dp.end())
		return dp[i];

	ll g = fastPow(2, i - 1);

	vi divisors = getDiv(i);
	FOR(intI, 0, divisors.size())
	{
		g -= f(i / divisors[intI]);
		g = (g + MOD) % MOD;
	}

	g %= MOD;
	dp.insert(mp(i, g));

	return g;
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll x, y;
	scanf("%lld %lld", &x, &y);

	if (y % x != 0)
	{
		printf("0\n");
	}
	else
	{
		printf("%lld\n", f(y / x));
	}

	return 0;
}

//====================================================================================================================== 