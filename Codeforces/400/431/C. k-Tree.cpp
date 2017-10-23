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
ll dp[105][5];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intK, intD;

	cin >> intN >> intK >> intD;
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	dp[0][1] = 0;

	FOR(intI, 1, intN + 1)
	{
		dp[intI][0] = dp[intI][1] = 0;

		FOR(intJ, 1, intK + 1)
		{
			if (intI - intJ < 0) break;
			if (intJ < intD)
			{
				dp[intI][0] += dp[intI - intJ][0] % 1000000007;
				dp[intI][1] += dp[intI - intJ][1] % 1000000007;
			}
			else
			{
				dp[intI][1] += dp[intI - intJ][0] % 1000000007 + dp[intI - intJ][1] % 1000000007;
			}
		}
	}

	cout << dp[intN][1] % 1000000007 << endl;

	return 0;
}

//======================================================================================================================