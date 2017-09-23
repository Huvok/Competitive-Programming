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
	ll intN, intV1, intV2, intL1, intL2;

	cin >> intN >> intV1 >> intV2 >> intL1 >> intL2;

	if (intL1 * 2 + intV1 * intN > intL2 * 2 + intV2 * intN)
	{
		cout << "Second" << endl;
	}
	else if (intL1 * 2 + intV1 * intN < intL2 * 2 + intV2 * intN)
	{
		cout << "First" << endl;
	}
	else
	{
		cout << "Friendship" << endl;
	}

	return 0;
}
//======================================================================================================================