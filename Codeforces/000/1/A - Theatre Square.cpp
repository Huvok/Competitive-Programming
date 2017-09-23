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
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	unsigned long long int intA, intB, intSize, intR1 = 0, intR2 = 0, intCount;
	cin >> intA >> intB >> intSize;

	if (intA % intSize > 0)
	{
		intR1 = 1;
	}

	if (intB % intSize > 0)
	{
		intR2 = 1;
	}

	intCount = (((intA / intSize) + intR1) * ((intB / intSize) + intR2));
	cout << intCount << endl;

	return 0;

	return 0;
}
//======================================================================================================================