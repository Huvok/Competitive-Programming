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
ll dp[105][105][5];

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll n1, n2, k1, k2;
	cin >> n1 >> n2 >> k1 >> k2;
	memset(dp, 0, sizeof(dp));

	dp[0][0][0] = dp[0][0][1] = 1;
	FOR(i, 0, n1 + 1)
	{
		FOR(j, 0, n2 + 1)
		{
			FOR(k, 1, k1 + 1)
			{
				if (i - k < 0)
					break;

				dp[i][j][0] += dp[i - k][j][1];
				dp[i][j][0] %= 100000000;
			}

			FOR(k, 1, k2 + 1)
			{
				if (j - k < 0)
					break;

				dp[i][j][1] += dp[i][j - k][0];
				dp[i][j][1] %= 100000000;
			}
		}
	}

	cout << (dp[n1][n2][0] + dp[n1][n2][1]) % 100000000 << endl;

	return 0;
}

//====================================================================================================================== 