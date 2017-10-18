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
ll fact[5005], rfact[5005];

ll NK(int N, int K) {
	return fact[N] * rfact[K] % 998244353 * rfact[N - K] % 998244353;
}

ll fastPow(ll x, ll n) {
	ll ret = 1;
	while (n) {
		if (n & 1) ret = ret*x% 998244353;
		x = x*x% 998244353;
		n >>= 1;
	}
	return ret;
}

//----------------------------------------------------------------------------------------------------------------------
#define MOD 998244353
int main()
{
	fact[0] = 1;
	FOR(i, 1, 5005) fact[i] = fact[i - 1] * i % 998244353;
	rfact[5005 - 1] = fastPow(fact[5005 - 1], 998244353 - 2);
	for (int i = 5005 - 2; i >= 0; i--) rfact[i] = rfact[i + 1] * (i + 1) % 998244353;

	ll a, b, c;
	cin >> a >> b >> c;

	ll ans1 = 0, ans2 = 0, ans3 = 0;

	FOR(intI, 0, min(a, b) + 1)
	{
		ans1 += (NK(a, intI) % MOD * NK(b, intI) % MOD * fact[intI] % MOD);
		ans1 %= MOD;
	}

	FOR(intI, 0, min(b, c) + 1)
	{
		ans2 += (NK(b, intI) % MOD * NK(c, intI) % MOD * fact[intI] % MOD);
		ans2 %= MOD;
	}

	FOR(intI, 0, min(c, a) + 1)
	{
		ans3 += (NK(c, intI) % MOD * NK(a, intI) % MOD * fact[intI] % MOD);
		ans3 %= MOD;
	}

	cout << ans1 % MOD * ans2 % MOD * ans3 % MOD << endl;

	return 0;
}

//======================================================================================================================