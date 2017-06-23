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
	ll intT, intN, intIn, intHigh, intLow, intPast, intPastHigh, intPastLow;

	scanf("%lld", &intT);
	for (ll intI = 0; intI < intT; ++intI)
	{
		scanf("%lld", &intN);
		intHigh = 0;
		intLow = 0;
		for (ll intJ = 0; intJ < intN; ++intJ)
		{
			scanf("%lld", &intIn);

			if (!intJ)
			{
				//											//Do nothing.
			}
			else
			{
				intLow = max(intPastLow, intPastHigh + abs(intPast - 1));
				intHigh = max(intPastLow + abs(intIn - 1), intPastHigh + abs(intPast - intIn));
			}

			intPastLow = intLow;
			intPastHigh = intHigh;
			intPast = intIn;
		}

		printf("%lld\n", max(intLow, intHigh));
	}

	return 0;
}
//======================================================================================================================