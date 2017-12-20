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
ll n, m;
string str;
set<ll> ind[65];
ll tree[200005];

ll getIndex(char c) 
{
	if (c >= 'a' && c <= 'z')
		return c - 'a';
	if (c >= 'A' && c <= 'Z')
		return c - 'A' + 26;
	return c - '0' + 52;
}

ll query(ll i)
{
	ll ans = 0;
	while (i > 0)
	{
		ans += tree[i];
		i -= i & -i;
	}

	return ans;
}

ll getRealIndex(ll x)
{
	ll l = 1, r = n;
	while (l < r)
	{
		ll m = ((r - l) >> 1) + l;
		if (m - query(m) >= x)
			r = m;
		else
			l = m + 1;
	}

	return l;
}

void update(ll i, ll x)
{
	while (i < 200005)
	{
		tree[i] += x;
		i += i & -i;
	}
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	cin >> n >> m >> str;
	FOR(i, 0, n)
	{
		ind[getIndex(str[i])].insert(i + 1);
	}

	while (m--) 
	{
		ll l, r;
		char c;
		scanf("%lld %lld %c", &l, &r, &c);
		ll x = getIndex(c);
		l = getRealIndex(l);
		r = getRealIndex(r);
		auto it = ind[x].lower_bound(l);
		while (it != ind[x].end() &&
			*it <= r)
		{
			update(*it, 1);
			ind[x].erase(it++);
		}
	}

	FOR(i, 0, n)
	{
		if (query(i + 1) == query(i))
		{
			printf("%c", str[i]);
		}
	}

	printf("\n");
	return 0;
}

//====================================================================================================================== 