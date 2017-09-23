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
	int intN, intK, intAux, intCount = 0, intPast = -100;

	cin >> intN >> intK;

	for (int intI = 1; intI <= intN; ++intI)
	{
		cin >> intAux;

		if (intI <= intK && intAux > 0)
		{
			intCount++;
		}
		else if (intAux == intPast && intAux > 0)
		{
			intCount++;
		}
		else
		{
			break;
		}

		intPast = intAux;
	}

	cout << intCount << endl;

	return 0;
}
//======================================================================================================================