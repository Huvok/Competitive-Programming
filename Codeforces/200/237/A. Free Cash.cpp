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
	ll intN, intH, intM, intHPrev, intMPrev;
	intHPrev = -1, intMPrev = -1;
	ll intCount = 1;

	cin >> intN;
	ll intNeeded = 0;
	FOR(intI, 0, intN)
	{
		cin >> intH >> intM;
		if (intH != intHPrev || intM != intMPrev)
		{
			intNeeded = 1;
		}
		else
		{
			intNeeded++;
			if (intNeeded > intCount) intCount = intNeeded;
		}

		intHPrev = intH;
		intMPrev = intM;
	}

	cout << intCount << endl;

	return 0;
}

//======================================================================================================================