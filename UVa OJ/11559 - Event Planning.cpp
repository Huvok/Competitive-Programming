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
	ll intN, intBudget, intHotels, intWeeks, intPrice, intSize;

	while (scanf("%lld %lld %lld %lld", &intN, &intBudget, &intHotels, &intWeeks) == 4)
	{
		ll cost = 0;
		for (int i = 0; i < intHotels; i++) 
		{
			scanf("%lld", &intPrice);

			for (int j = 0; j < intWeeks; j++) 
			{
				scanf("%lld", &intSize);
				if (intSize >= intN && intN * intPrice <= intBudget)
				{
					if (cost == 0 || intN * intPrice < cost)
					{
						cost = intN * intPrice;
					}
				}
			}
		}

		printf(cost == 0 ? "stay home\n" : "%lld\n", cost);
	}


	return 0;
}
//======================================================================================================================