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

//======================================================================================================================
ll intN, K, mask;
ll stains[1005][2];
ll arr[1005];
ll dp[1005][1005][18];
ll vals[4] = { 0, 10000000, 0, 10000000 };

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intX, intY;

	scanf("%lld %lld", &intN, &K);
	K = intN - K;

	if (!K)
	{
		printf("1\n");
		return 0;
	}

	memset(dp, 0, sizeof dp);


	for (ll intI = 1; intI <= intN; ++intI)
	{
		scanf("%lld %lld", &intX, &intY);
		stains[intI][0] = intX;
		stains[intI][1] = intY;

		vals[0] = max(vals[0], intX);
		vals[1] = min(vals[1], intX);
		vals[2] = max(vals[2], intY);
		vals[3] = min(vals[3], intY);
	}

	for (ll intI = 1; intI <= intN; ++intI)
	{
		mask = 0;

		for (ll intJ = 0; intJ < 4; ++intJ)
		{
			if (vals[intJ] == stains[intI][intJ / 2])
			{
				mask |= (1 << intJ);
			}
		}

		arr[intI] = mask;
	}

	for (ll intI = 1; intI <= intN; ++intI)
	{
		dp[1][intI][arr[intI]] = 1;

		for (ll intJ = 0; intJ < 16; ++intJ)
		{
			dp[1][intI][intJ] += dp[1][intI - 1][intJ];
		}
	}

	for (ll intI = 1; intI < K; ++intI)
	{
		for (ll intJ = intI; intJ < intN; ++intJ)
		{
			for (ll intK = 0; intK < 16; ++intK)
			{
				dp[intI + 1][intJ + 1][intK | arr[intJ + 1]] = (dp[intI + 1][intJ + 1][intK | arr[intJ + 1]] + dp[intI][intJ][intK]) % 1000000007;
				dp[intI + 1][intJ + 1][intK] = (dp[intI + 1][intJ + 1][intK] + dp[intI + 1][intJ][intK]) % 1000000007;
			}
		}
	}

	ll intSol = 0;

	for (ll intI = 0; intI < 15; ++intI)
	{
		intSol = (intSol + dp[K][intN][intI]) % 1000000007;
	}

	printf("%lld\n", intSol);

	return 0;
}
//======================================================================================================================