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

using namespace std;

//															//AUTHOR: Hugo Garcia
//															//PURPOSE: Competitive programming template

//======================================================================================================================

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

//======================================================================================================================
ll dp[2005], arr[2005];
//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intT, intN, intSum;

	scanf("%lld", &intT);

	while (intT--)
	{
		scanf("%lld %lld", &intN, &intSum);

		for (ll intI = 0; intI < intN; intI++)
		{
			scanf("%lld", &arr[intI]);
		}

		memset(dp, 0, sizeof dp);
		for (ll intI = 1; intI <= intSum; intI++)
		{
			dp[intI] = dp[intI - 1];
			for (ll intJ = 0; intJ < intN; intJ++)
			{
				if (intI - arr[intJ] >= 0)
				{
					dp[intI] = max(dp[intI], dp[intI - arr[intJ]] + arr[intJ]);
				}
			}
		}

		printf("%lld\n", dp[intSum]);
	}

	return 0;
}
//======================================================================================================================