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
bool dp[305][305];

void propagate(ll i, ll j)
{
	FOR(I, i + 1, 301)
		dp[I][j] = 1;
	FOR(J, j + 1, 301)
		dp[i][J] = 1;
	for (ll k = 1; i + k < 301 && j + k < 301; k++)
	{
		dp[i + k][j + k] = 1;
	}
}

void calc()
{
	memset(dp, 0, sizeof(dp));
	FOR(i, 0, 301)
	{
		FOR(j, 0, 301)
		{
			if (!dp[i][j])
				propagate(i, j);
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll n;
	cin >> n;
	if (n == 1)
	{
		ll x;
		cin >> x;
		if (x)
			cout << "BitLGM" << endl;
		else
			cout << "BitAryo" << endl;
	}
	else if (n == 2)
	{
		ll x, y;
		cin >> x >> y;
		calc();
		if (dp[x][y])
			cout << "BitLGM" << endl;
		else
			cout << "BitAryo" << endl;
	}
	else
	{
		ll x, y, z;
		cin >> x >> y >> z;
		if ((x ^ y ^ z) != 0)
			cout << "BitLGM" << endl;
		else
			cout << "BitAryo" << endl;
	}

	return 0;
}

//====================================================================================================================== 