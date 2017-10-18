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
ll S(ll i)
{
	string s = to_string(i);
	ll intSum = 0;
	FOR(intI, 0, s.length())
	{
		intSum += s[intI] - '0';
	}

	return intSum;
}

ll fastPow(ll x, ll n) {
	ll ret = 1;
	while (n) {
		if (n & 1) ret = ret*x;
		x = x * x;
		n >>= 1;
	}
	return ret;
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll a, b, c;
	cin >> a >> b >> c;
	vi ans;
	FOR(intI, 1, 82)
	{
		ll i = b * fastPow(intI, a) + c;

		if (i > 0 && i < 10e8 && intI == S(i))
		{
			ans.pb(i);
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << endl;
	FOR(intI, 0, ans.size())
	{
		cout << ans[intI] << " ";
	}

	cout << endl;

	return 0;
}

//======================================================================================================================