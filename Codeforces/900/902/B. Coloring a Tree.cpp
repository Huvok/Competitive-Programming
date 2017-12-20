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
vi AdjList[50005];
ll col[50005];
bool vis[50005];
bool change;

void paint(ll i, ll x)
{
	col[i] = x;

	FOR(j, 0, AdjList[i].size())
	{
		ll u = AdjList[i][j];

		paint(u, x);
	}
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll n;
	scanf("%lld", &n);
	ll x;
	FOR(i, 2, n + 1)
	{
		scanf("%lld", &x);
		AdjList[x].pb(i);
	}

	ll ans = 0;
	FOR(i, 1, n + 1)
		col[i] = -1;

	change = false;
	FOR(i, 0, n)
	{
		scanf("%lld", &x);
		if (col[i + 1] != x)
		{
			ans++;
			paint(i + 1, x);
			change = true;
		}
	}

	printf("%lld\n", ans);

	return 0;
}

//====================================================================================================================== 