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

ll arr[100005], dp[100005];
//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intSum = 0, intNext;
	bool boolDown = false;

	scanf("%lld", &intN);

	for (ll intI = 1; intI <= intN; ++intI)
	{
		scanf("%lld", &intNext);
		arr[intI] = intNext;
	}

	arr[0] = 100005;
	arr[intN + 2] = 100005;

	for (ll intI = 1; intI <= intN; ++intI)
	{
		if (arr[intI] <= arr[intI - 1] &&
			arr[intI] <= arr[intI + 1])
		{
			dp[intI] = 1;
		}
	}

	for (ll intI = 1; intI <= intN; ++intI)
	{
		if (arr[intI] > arr[intI - 1] &&
			arr[intI] <= arr[intI + 1])
		{
			dp[intI] = dp[intI - 1] + 1;
		}
	}

	for (ll intI = intN; intI >= 1; --intI)
	{
		if (arr[intI] <= arr[intI - 1] &&
			arr[intI] > arr[intI + 1])
		{
			dp[intI] = dp[intI + 1] + 1;
		}
	}

	for (ll intI = 1; intI <= intN; ++intI)
	{
		if (arr[intI] > arr[intI - 1] &&
			arr[intI] > arr[intI + 1])
		{
			dp[intI] = max(dp[intI + 1], dp[intI - 1]) + 1;
		}

		intSum += dp[intI];
	}

	printf("%lld\n", intSum);

	return 0;
}
//======================================================================================================================