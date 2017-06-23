#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>

using namespace std;

//															//AUTHOR: Hugo García
//															//PURPOSE: Competitive programming template

//======================================================================================================================
typedef long long ll;

//======================================================================================================================
int main()
{
	ll intN, intT, intNext, intChamp;

	scanf("%lld", &intT);

	for (ll intI = 0; intI < intT; ++intI)
	{
		scanf("%lld", &intN);

		for (ll intJ = 0; intJ < intN; ++intJ)
		{
			scanf("%lld", &intNext);

			if (!intJ)
			{
				intChamp = intNext;
			}
			else
			{
				intChamp = max(intChamp, intNext);
			}
		}

		printf("Case %lld: %lld\n", intI + 1, intChamp);
	}


	return 0;
}
//======================================================================================================================