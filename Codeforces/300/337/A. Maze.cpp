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
string init[505];
string ans[505];
bool vis[505][505];
ll n, m, k, cur;

void dfs(ll i, ll j)
{
	if (cur <= 0)
		return;
	vis[i][j] = true;
	ans[i][j] = '.';
	cur--;

	if (i < n - 1 &&
		!vis[i + 1][j] &&
		init[i + 1][j] != '#')
		dfs(i + 1, j);
	if (i > 0 &&
		!vis[i - 1][j] &&
		init[i - 1][j] != '#')
		dfs(i - 1, j);
	if (j < m - 1 &&
		!vis[i][j + 1] &&
		init[i][j + 1] != '#')
		dfs(i, j + 1);
	if (j > 0 &&
		!vis[i][j - 1] &&
		init[i][j - 1] != '#')
		dfs(i, j - 1);
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	cin >> n >> m >> k;
	ll s = 0;
	FOR(i, 0, n)
	{
		cin >> init[i];
		ans[i] = init[i];
	}

	FOR(i, 0, n)
	{
		FOR(j, 0, m)
		{
			ans[i][j] = 'X';
			if (init[i][j] == '.')
				s++;
		}
	}

	cur = s - k;
	FOR(i, 0, n)
	{
		FOR(j, 0, m)
		{
			if (init[i][j] == '.')
			{
				dfs(i, j);
				i == n;
				j == m;
			}
		}
	}

	FOR(i, 0, n)
	{
		FOR(j, 0, m)
		{
			if (init[i][j] == '#')
				cout << '#';
			else
				cout << ans[i][j];
		}

		cout << endl;
	}

	return 0;
}

//====================================================================================================================== 