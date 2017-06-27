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

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intT;
	ll arr[205][205];

	scanf("%lld", &intT);

	while (intT--)
	{
		scanf("%lld", &intN);
		memset(arr, 0, sizeof arr);

		for (ll intI = 0; intI < intN; intI++)
		{
			for (ll intJ = 0; intJ < intN; intJ++)
			{
				scanf("%lld", &arr[intI][intJ]);
				arr[intI][intJ + intN] = arr[intI + intN][intJ] = arr[intI + intN][intJ + intN] = arr[intI][intJ];
			}
		}

		for (ll intI = 0; intI < intN * 2; intI++)
		{
			for (ll intJ = 0; intJ < intN * 2; intJ++)
			{
				if (intI > 0) arr[intI][intJ] += arr[intI - 1][intJ];
				if (intJ > 0) arr[intI][intJ] += arr[intI][intJ - 1];
				if (intI > 0 && intJ > 0) arr[intI][intJ] -= arr[intI - 1][intJ - 1];
			}
		}

		ll intResult = -5000000000;
		ll intSubRect;
		for (ll intI = 0; intI < intN; intI++)
		{
			for (ll intJ = 0; intJ < intN; intJ++)
			{
				for (ll intK = intI; intK < intI + intN; intK++)
				{
					for (ll intL = intJ; intL < intJ + intN; intL++)
					{
						intSubRect = arr[intK][intL];
						if (intI > 0) intSubRect -= arr[intI - 1][intL];
						if (intJ > 0) intSubRect -= arr[intK][intJ - 1];
						if (intI > 0 && intJ > 0) intSubRect += arr[intI - 1][intJ - 1];

						intResult = max(intResult, intSubRect);
					}
				}
			}
		}

		printf("%lld\n", intResult);
	}
	return 0;
}
//======================================================================================================================