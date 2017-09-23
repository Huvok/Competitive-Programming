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
	ll intN, intS;
	cin >> intN >> intS;

	ll intL = 1, intR = intN;

	while (intL <= intR)
	{
		ll intMiddle = (intR - intL) / 2 + intL;

		ll intSum = 0;
		ll intRem = intMiddle;
		while (intRem)
		{
			intSum += (intRem % 10);
			intRem /= 10;
		}

		if (intMiddle - intSum >= intS)
		{
			intR = intMiddle - 1;
		}
		else
		{
			intL = intMiddle + 1;
		}
	}

	cout << intN - intR << endl;

	return 0;
}
//======================================================================================================================