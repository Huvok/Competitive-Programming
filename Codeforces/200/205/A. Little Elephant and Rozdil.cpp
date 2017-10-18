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
	ll intN;
	cin >> intN;
	ll intMin = INT_MAX;
	ll intChamp = 0;
	bool bad = false;

	FOR(intI, 0, intN)
	{
		ll intNext;
		cin >> intNext;
		if (intNext < intMin)
		{
			intChamp = intI + 1;
			intMin = intNext;
			bad = false;
		}
		else if (intNext == intMin) bad = true;
	}

	if (bad)
	{
		cout << "Still Rozdil" << endl;
	}
	else
	{
		cout << intChamp << endl;
	}

	return 0;
}
//======================================================================================================================