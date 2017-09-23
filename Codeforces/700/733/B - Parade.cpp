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
ll l[100005], r[100005];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN;
	cin >> intN;

	ll intMaxL = 0, intMaxR = 0;
	FOR(intI, 0, intN)
	{
		cin >> l[intI] >> r[intI];
		intMaxL += l[intI];
		intMaxR += r[intI];
	}

	ll intMaxK = abs(intMaxL - intMaxR);

	ll intIndex = 0;
	FOR(intI, 0, intN)
	{
		if (abs((intMaxL - l[intI] + r[intI]) - (intMaxR - r[intI] + l[intI])) > intMaxK)
		{
			intMaxK = abs((intMaxL - l[intI] + r[intI]) - (intMaxR - r[intI] + l[intI]));
			intIndex = intI + 1;
		}
	}

	cout << intIndex << endl;

	return 0;
}
//======================================================================================================================