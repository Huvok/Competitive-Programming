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
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

using namespace std;

//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll n, k;
	string str;
	cin >> n >> k;
	cin >> str;

	if (k > n / 2)
	{
		reverse(all(str));
		k = (n - k + 1);
	}

	k--;
	ll l = k, r = k;
	ll idx = k;
	while (idx >= 0)
	{
		if (str[idx] != str[n - idx - 1])
			l = idx;
		idx--;
	}

	idx = k;
	while (idx < n / 2)
	{
		if (str[idx] != str[n - idx - 1])
			r = idx;
		idx++;
	}

	ll ans = (k - l) + (r - k);
	ans += (min(k - l, r - k));
	while (k >= l)
	{
		ll low = min(str[k], str[n - k - 1]);
		ll high = max(str[k], str[n - k - 1]);
		ans += min(abs(low - high), abs(low + 26 - high));
		str[k] = str[n - k - 1];
		k--;
	}

	k = l;
	while (k <= r)
	{
		ll low = min(str[k], str[n - k - 1]);
		ll high = max(str[k], str[n - k - 1]);
		ans += min(abs(low - high), abs(low + 26 - high));
		k++;
	}

	cout << ans << endl;

	return 0;
}

//====================================================================================================================== 