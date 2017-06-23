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
const int MAXN = 131072;
ll intN, arr[MAXN];

//----------------------------------------------------------------------------------------------------------------------
ll gcd(ll a, ll b) 
{
	if (b) return gcd(b, a % b);
	return a;
}

//----------------------------------------------------------------------------------------------------------------------
ll intCalculateWays(ll intSize) 
{
	if (arr[0] / intSize <= intN) return 0;

	ll intVarietyPack = arr[0] / intSize % intN;

	for (ll intI = 0; intI < intN; intI++)
	{
		if (arr[intI] / intSize % intN != intVarietyPack)
		{
			return 0;
		}
	}

	ll intWays = arr[0] / intSize / intN;

	if (intVarietyPack == 0)
	{
		intWays--;
	}

	return intWays;
}

//----------------------------------------------------------------------------------------------------------------------
int main() 
{
	while (scanf("%d", &intN) == 1 && intN)
	{
		for (ll intI = 0; intI < intN; intI++)
		{
			scanf("%d", &arr[intI]);
		}

		sort(arr, arr + intN);
		ll intGCD = arr[0];
		ll intResult = 0;
		for (ll intI = 0; intI < intN; intI++)
		{
			intGCD = gcd(intGCD, arr[intI]);
		}

		for (int intI = 1; intI * intI <= intGCD; intI++)
		{
			if (intGCD % intI == 0)
			{
				intResult += intCalculateWays(intI);

				if (intI * intI != intGCD)
				{
					intResult += intCalculateWays(intGCD / intI);
				}
			}
		}

		printf("%lld\n", intResult);
	}
	return 0;
}
//======================================================================================================================