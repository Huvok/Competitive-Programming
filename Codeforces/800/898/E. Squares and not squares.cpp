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
ll arr[200005], dist[2000005];
vi squares;

bool is(ll i)
{
	ll ans = sqrt(i);
	if (i == ans * ans)
		return true;
	else
		return false;
}

ll getDist(ll i)
{
	auto l = lower_bound(all(squares), i) - squares.begin();
	if (l)
		return min(i - squares[l - 1], squares[l] - i);

	return squares[l] - i;
}

void precalc()
{
	ll cur = 0;
	while (cur * cur <= 1000050000)
	{
		squares.pb(cur * cur);
		cur++;
	}
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll n;
	scanf("%lld", &n);
	precalc();
	ll ans = 0;
	FOR(i, 0, n)
	{
		scanf("%lld", &arr[i]);
	}

	ll c1 = 0, c2 = 0;
	FOR(i, 0, n)
	{
		if (is(arr[i]))
			c1++;
		else
			c2++;
	}

	if (c1 > c2)
	{
		sort(arr, arr + n);
		ll count = 0;
		RFOR(i, n - 1, 0)
		{
			if (is(arr[i]))
			{
				if (arr[i])
					ans++;
				else
					ans += 2;
				count++;
				if (count >= (c1 - c2) / 2)
					break;
			}
		}
	}
	else if (c2 > c1)
	{
		FOR(i, 0, n)
		{
			dist[i] = getDist(arr[i]);
		}

		sort(dist, dist + n);
		FOR(i, c1, (c2 - c1) / 2 + c1)
		{
			ans += dist[i];
		}
	}

	cout << ans << endl;

	return 0;
}

//====================================================================================================================== 