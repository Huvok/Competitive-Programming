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

using namespace std;

//															//AUTHOR: Hugo Garcia
//															//PURPOSE: Competitive programming template

//======================================================================================================================

typedef long long ll;
typedef vector<ll> vi;
#define intMaxN 10000

//======================================================================================================================

ll arr[intMaxN + 5];
ll dp[intMaxN + 5];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intAux, intChamp;
	while (true)
	{
		scanf("%lld", &intN);

		if (!intN)
		{
			break;
		}

		for (ll intI = 0; intI < intN; ++intI)
		{
			scanf("%lld", &intAux);
			arr[intI] = intAux;
		}

		intAux = 0;
		intChamp = 0;
		for (ll intI = 0; intI < intN; ++intI)
		{
			intAux = max(intAux + arr[intI], arr[intI]);
			intChamp = max(intChamp, intAux);
		}

		if (intChamp < 1)
		{
			printf("Losing streak.\n");
		}
		else
		{
			printf("The maximum winning streak is %lld.\n", intChamp);
		}
	}

	return 0;
}
//======================================================================================================================