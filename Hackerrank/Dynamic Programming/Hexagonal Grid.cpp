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
ll intN, arr[25] = {};
ll dp[25];

ll solve(ll intState)
{
	if (intState >= intN * 2) return dp[intState] = 1;
	if (intState == intN * 2 - 1 && arr[intState] == 0) return dp[intState] = 0;

	if (dp[intState] != -1)
	{
		return dp[intState];
	}

	if (arr[intState]) return solve(intState + 1);

	ll intA, intB;
	if (arr[intState + 1] == 0 &&
		arr[intState + 2] == 0)
	{
		arr[intState + 1] = 1;
		intA = solve(intState + 2);
		arr[intState + 1] = 0;
		arr[intState + 2] = 1;
		intB = solve(intState + 1);
		arr[intState + 2] = 0;
		return dp[intState] = max(intA, intB);
	}
	else if (arr[intState + 1] == 0)
	{
		arr[intState + 1] = 1;
		intA = solve(intState + 2);
		arr[intState + 1] = 0;
		return dp[intState] = intA;
	}
	else if (arr[intState + 2] == 0 && intState + 2 < intN * 2)
	{
		arr[intState + 2] = 1;
		intA = solve(intState + 1);
		arr[intState + 2] = 0;
		return dp[intState] = intA;
	}
	else
	{
		return 0;
	}
}

//----------------------------------------------------------------------------------------------------------------------
int main() 
{
	ll intT;
	string str1, str2;

	scanf("%lld", &intT);

	while (intT--)
	{
		scanf("%lld", &intN);
		cin >> str1 >> str2;

		memset(arr, 0, sizeof arr);
		memset(dp, -1, sizeof dp);

		ll intIndex = 0;
		for (ll intI = 0; intI < intN * 2; intI += 2)
		{
			if (str1[intIndex] == '1')
			{
				arr[intI] = 1;
			}

			intIndex++;
		}

		intIndex = 0;
		for (ll intI = 1; intI < intN * 2; intI += 2)
		{
			if (str2[intIndex] == '1')
			{
				arr[intI] = 1;
			}

			intIndex++;
		}

		if (solve(0))
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}

	return 0;
}
//======================================================================================================================