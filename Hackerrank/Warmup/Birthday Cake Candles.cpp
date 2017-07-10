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
	ll intN;
	cin >> intN;

	ll intCount = 0, intChamp = -1, intCur;
	for (ll intI = 0; intI < intN; intI++)
	{
		cin >> intCur;
		if (intCur > intChamp)
		{
			intChamp = intCur;
			intCount = 1;
		}
		else if (intCur == intChamp)
		{
			intCount++;
		}
	}

	cout << intCount << endl;
	
	return 0;
}
//======================================================================================================================