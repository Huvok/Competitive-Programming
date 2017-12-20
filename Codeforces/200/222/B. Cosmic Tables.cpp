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
ll mat[1005][1005];
ll x[1005], y[1005];

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll n, m, q;
	scanf("%lld %lld %lld", &n, &m, &q);

	FOR(i, 0, n)
	{
		FOR(j, 0, m)
		{
			scanf("%lld", &mat[i][j]);
		}
	}

	FOR(i, 0, n)
		x[i] = i;
	FOR(i, 0, m)
		y[i] = i;

	ll b, c;
	char a;
	FOR(i, 0, q)
	{
		scanf("%s %lld %lld", &a, &b, &c);
		if (a == 'r')
		{
			c--; b--;
			swap(x[c], x[b]);
		}
		else if (a == 'c')
		{
			c--; b--;
			swap(y[c], y[b]);
		}
		else
		{
			b--; c--;
			printf("%lld\n", mat[x[b]][y[c]]);
		}
	}

	return 0;
}

//====================================================================================================================== 