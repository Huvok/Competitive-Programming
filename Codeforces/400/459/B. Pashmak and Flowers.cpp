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
#include <unordered_set>

using namespace std;

//															//AUTHOR: Hugo Garcia
//															//PURPOSE: Competitive programming template

//======================================================================================================================

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define pb push_back
#define mp make_pair
#define lld I64d

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intMax, intCMax, intMin, intCMin;
	intCMax = intCMin = 0;
	intMax = -9;
	intMin = INT_MAX;
	ll intNext;

	cin >> intN;
	FOR(intI, 0, intN)
	{
		cin >> intNext;
		if (intNext > intMax)
		{
			intMax = intNext;
			intCMax = 1;
		}
		else if (intNext == intMax) intCMax++;

		if (intNext < intMin)
		{
			intMin = intNext;
			intCMin = 1;
		}
		else if (intNext == intMin) intCMin++;
	}

	if (intMax == intMin)
	{
		cout << 0 << " " << intN * (intN - 1) / 2 << endl;
	}
	else
	{
		cout << intMax - intMin << " " << intCMax * intCMin << endl;
	}

	return 0;
}

//======================================================================================================================