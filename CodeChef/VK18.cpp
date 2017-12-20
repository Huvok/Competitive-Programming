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
ll dp[2000005];

ll getD(ll i)
{
	string s = to_string(i);
	ll odd = 0, even = 0;
	FOR(j, 0, s.length())
	{
		if ((s[j] - '0') & 1)
		{
			odd += (s[j] - '0');
		}
		else
		{
			even += (s[j] - '0');
		}
	}

	return abs(even - odd);
}

//----------------------------------------------------------------------------------------------------------------------
ll ans[1000005];
int main()
{
	dp[0] = 2;
	ans[0] = 2;
	FOR(i, 1, 2000001)
	{
		dp[i] = getD(i + 2);
	}

	FOR(i, 1, 2000001)
		dp[i] = dp[i] + dp[i - 1];

	FOR(i, 1, 1000001)
	{
		ans[i] = ans[i - 1] + 2 * (dp[2 * i - 1] - dp[i - 1]) + dp[2 * i] - dp[2 * i - 1];
	}

	ll intT, intN;
	scanf("%lld", &intT);

	while (intT--)
	{
		scanf("%lld", &intN);

		printf("%lld\n", ans[intN - 1]);
	}
	return 0;
}

//======================================================================================================================