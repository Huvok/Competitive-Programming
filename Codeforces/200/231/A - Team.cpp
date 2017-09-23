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
	int intN;
	cin >> intN;
	int int1, int2, int3, intCount = 0;

	for (int intI = 0; intI < intN; intI++)
	{
		cin >> int1 >> int2 >> int3;

		if (int1 + int2 + int3 >= 2)
		{
			intCount++;
		}
	}

	cout << intCount << endl;

	return 0;
}
//======================================================================================================================