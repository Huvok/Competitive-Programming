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
ll gcd(ll a, ll b)
{
	if (!b)
		return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b, ll c) 
{
	ll x = (a * b / gcd(a, b));
	ll y = (x * c / gcd(x, c));
	return y;
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll n;
	cin >> n;
	
	ll ans = 0;
	ll s = max(n - 20, 1LL);
	FOR(i, s, n + 1)
	{
		FOR(j, s, n + 1)
		{
			FOR(k, s, n + 1)
			{
				ans = max(ans, lcm(i, j, k));
			}
		}
	}

	cout << ans << endl << endl;

	return 0;
}

//====================================================================================================================== 