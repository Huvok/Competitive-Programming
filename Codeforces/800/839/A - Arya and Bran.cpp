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
	ll intN, intK;
	cin >> intN >> intK;

	ll intCount = 0, intNow;
	FOR(intI, 0, intN)
	{
		cin >> intNow;
		intCount += intNow;

		if (intCount >= 8)
		{
			intK -= 8;
			intCount -= 8;
		}
		else
		{
			intK -= intCount;
			intCount = 0;
		}

		if (intK <= 0)
		{
			cout << intI + 1 << endl;
			break;
		}
	}

	if (intK > 0)
	{
		cout << -1 << endl;
	}

	return 0;
}
//======================================================================================================================