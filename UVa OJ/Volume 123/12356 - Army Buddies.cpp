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

ll arrL[100005], arrR[100005];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intQ, intL, intR;

	while (true)
	{
		scanf("%lld %lld", &intN, &intQ);

		if (!intN) break;

		for (ll intI = 1; intI < intN; ++intI)
		{
			arrL[intI] = intI - 1;
			arrR[intI] = intI + 1;
		}

		arrL[1] = -1;
		arrR[intN] = -1;

		for (ll intI = 0; intI < intQ; ++intI)
		{
			scanf("%lld %lld", &intL, &intR);

			arrL[arrR[intR]] = arrL[intL];
			if (arrL[intL] == -1)
			{
				printf("* ");
			}
			else
			{
				printf("%lld ", arrL[intL]);
			}

			arrR[arrL[intL]] = arrR[intR];

			arrL[arrR[intR]] = arrL[intL];
			if (arrR[intR] == -1)
			{
				printf("*\n");
			}
			else
			{
				printf("%lld\n", arrR[intR]);
			}
		}

		printf("-\n");
	}

	return 0;
}
//======================================================================================================================