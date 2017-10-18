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

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intM, intK;
	cin >> intN >> intM >> intK;

	ll intL = 0, intH = intM;
	intK--;
	while (intL < intH)
	{
		ll intMiddle = (intH + intL) / 2 + 1;

		ll intSum = 0;

		if (intK != intN - 1)
		{
			if (intN - (intK + 1) >= intMiddle)
			{
				intSum += (intMiddle - 1) * (intMiddle) / 2;
				intSum += (intN - (intK + 1) - (intMiddle - 1));
			}
			else
			{
				intSum += (intMiddle - 1) * intMiddle / 2;
				intSum -= (intMiddle - (intN - (intK + 1))) * (intMiddle - ((intN - (intK + 1))) - 1) / 2;
			}
		}

		if (intK != 0)
		{
			if (intK >= intMiddle)
			{
				intSum += (intMiddle - 1) * (intMiddle) / 2;
				intSum += (intK - (intMiddle - 1));
			}
			else
			{
				intSum += (intMiddle - 1) * intMiddle / 2;
				intSum -= (intMiddle - (intK)) * (intMiddle - (intK)-1) / 2;
			}
		}

		if (intM >= intSum + intMiddle)
		{
			intL = intMiddle;
		}
		else if (intM < intSum + intMiddle)
		{
			intH = intMiddle - 1;
		}
	}

	cout << intL << endl;

	return 0;
}
//======================================================================================================================