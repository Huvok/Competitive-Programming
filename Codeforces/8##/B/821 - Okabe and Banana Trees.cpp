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
typedef pair<int, int> ii;
typedef vector<ii> vii;

//======================================================================================================================

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intM, intB;

	cin >> intM >> intB;

	ll intMax = 0;
	ll intCurrent, intY;

	for (ll intI = 0; intI <= intB * intM; intI++)
	{
		intY = -1.0 * intI / intM + intB;
		intCurrent = ((intY * (intY + 1)) / 2) * (intI + 1) + ((intI * (intI + 1)) / 2) * (intY + 1);
		intMax = max(intMax, intCurrent);
	}

	cout << intMax << endl;

	return 0;
}
//======================================================================================================================