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
#include <unordered_map>

using namespace std;

//															//AUTHOR: Hugo Garcia
//															//PURPOSE: Competitive programming template

//======================================================================================================================

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

//======================================================================================================================

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intT, intA, intB;
	cin >> intT;

	while (intT--)
	{
		cin >> intA >> intB;
		if (intA <= intB)
		{
			cout << 0 << endl;
			continue;
		}
		if (intA / intB < 2)
		{
			cout << intA % intB << endl;
			continue;
		}
		if (intB == 1)
		{
			if (intA % 2 == 0)
			{
				cout << (intA / 2) * (intA / 2) << endl;
				continue;
			}
			else
			{
				cout << (intA / 2) * (1 + intA / 2) << endl;
				continue;
			}
		}

		ll intRem = intA % intB;
		intA -= intRem;
		if (intA / 2 % intB == 0)
		{
			intRem += intA / 2;
			cout << intRem * (intA / 2 / intB) << endl;
		}
		else
		{
			ll intRes;
			intRes = max((intRem + intA / 2 + (intB - intA / 2 % intB)) * (intA / 2 / intB), (intRem + intA / 2 - (intA / 2 % intB)) * ((intA / 2 + (intB)) / intB));
			cout << intRes << endl;
		}
	}

	return 0;
}
//======================================================================================================================