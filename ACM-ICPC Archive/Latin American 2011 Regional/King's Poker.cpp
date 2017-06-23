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
	ll intA, intB, intC;

	while (true)
	{
		scanf("%lld %lld %lld", &intA, &intB, &intC);

		if (intA == 0) break;

		if (intA != intB &&
			intA != intC &&
			intB != intC)
		{
			printf("1 1 2\n");
		}
		else if (intA == intB &&
			intA == intC)
		{
			if (intA == 13)
			{
				printf("*\n");
			}
			else
			{
				printf("%lld %lld %lld\n", intA + 1, intB + 1, intC + 1);
			}
		}
		else
		{
			if (intA == intB)
			{
				if (intC + 1 == intA)
				{
					intC += 2;
				}
				else
				{
					intC++;
				}

				if (intC > 13)
				{
					intC = 1;
					intA++;
					intB++;
				}

				if (intA > 13)
				{
					intA = 1;
					intB = 1;
					intC = 1;
				}
			}
			else if (intA == intC)
			{
				if (intB + 1 == intA)
				{
					intB += 2;
				}
				else
				{
					intB++;
				}

				if (intB > 13)
				{
					intB = 1;
					intA++;
					intC++;
				}

				if (intA > 13)
				{
					intA = 1;
					intB = 1;
					intC = 1;
				}
			}
			else
			{
				if (intA + 1 == intB)
				{
					intA += 2;
				}
				else
				{
					intA++;
				}

				if (intA > 13)
				{
					intA = 1;
					intB++;
					intC++;
				}

				if (intB > 13)
				{
					intA = 1;
					intB = 1;
					intC = 1;
				}
			}

			ll arr[3];
			arr[0] = intA;
			arr[1] = intB;
			arr[2] = intC;

			sort(arr, arr + 3);

			printf("%lld %lld %lld\n", arr[0], arr[1], arr[2]);
		}
	}

	return 0;
}
//======================================================================================================================