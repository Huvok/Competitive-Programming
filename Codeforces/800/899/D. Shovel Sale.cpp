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
ll getFull(ll n)
{
	string s = to_string(n);
	s = s.substr(1);
	FOR(i, 0, s.length())
	{
		s[i] = '9';
	}

	return atoll(s.c_str());
}

ll get(ll n, ll i)
{
	if (i == 0)
		return n;
	if (n == 0)
		return i;
	string s = to_string(n);
	s = to_string(i) + s;
	return atoll(s.c_str());
}
//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll n;
	scanf("%lld", &n);

	ll fullNines = getFull(n * 2 - 1);
	if (n < 5)
	{
		cout << n * (n - 1) / 2 << endl;
	}
	else if (2 * n - 1 == fullNines * 10 + 9)
	{
		cout << 1 << endl;
	}
	else
	{
		ll ans = 0;
		FOR(i, 0, 9)
		{
			ll now = get(fullNines, i);
			if (now <= n)
				ans += now / 2;
			else if (now <= (2 * n - 1))
			{
				ans += n - now / 2;
			}
		}

		cout << ans << endl;
	}

	return 0;
}

//====================================================================================================================== 