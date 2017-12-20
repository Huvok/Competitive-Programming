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
vi AdjList[2005];
ii arr[105];
bool vis[2005];

void dfs(ll i)
{
	vis[i] = true;

	FOR(I, 0, AdjList[i].size())
	{
		ll u = AdjList[i][I];
		if (!vis[u])
			dfs(u);
	}
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll n;
	scanf("%lld", &n);
	FOR(i, 0, n)
	{
		scanf("%lld %lld", &arr[i].first, &arr[i].second);
		AdjList[arr[i].first].pb(arr[i].second + 1000);
		AdjList[arr[i].second + 1000].pb(arr[i].first);
	}

	ll ans = 0;
	FOR(i, 0, n)
	{
		if (!vis[arr[i].first])
		{
			ans++;
			dfs(arr[i].first);
		}
	}

	printf("%lld\n", ans - 1);

	return 0;
}

//====================================================================================================================== 