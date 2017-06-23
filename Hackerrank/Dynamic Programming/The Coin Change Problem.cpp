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
#define intMaxN 50

//======================================================================================================================

ll arr[intMaxN + 5];
ll intN, intM;
ll dp[intMaxN + 5][250];

ll intWays(ll intType, ll intV)
{
	if (intV == 0)
	{
		return 1;
	}

	if (intV < 0 || intType == intM)
	{
		return 0;
	}

	if (dp[intType][intV] != -1)
	{
		return dp[intType][intV];
	}

	return dp[intType][intV] = intWays(intType + 1, intV) + intWays(intType, intV - arr[intType]);
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	scanf("%lld %lld", &intN, &intM);
	memset(dp, -1, sizeof dp);
	for (ll intI = 0; intI < intM; ++intI)
	{
		scanf("%lld", &arr[intI]);
	}

	printf("%lld\n", intWays(0, intN));

	return 0;
}
//======================================================================================================================