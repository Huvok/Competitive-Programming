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
	ll intN;
	cin >> intN;

	ll intA = 1, intB = intN;

	ll intChamp = intN;
	FOR(intI, 1, intN)
	{
		if (!(intN % intI))
		{
			if (abs(intI - intN / intI) < intChamp)
			{
				intChamp = abs(intI - intN / intI);
				intA = min(intI, intN / intI);
				intB = max(intI, intN / intI);
			}
		}
	}

	cout << intA << " " << intB << endl;

	return 0;
}
//======================================================================================================================