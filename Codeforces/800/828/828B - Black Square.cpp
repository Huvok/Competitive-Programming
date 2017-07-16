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

//======================================================================================================================

//----------------------------------------------------------------------------------------------------------------------
ll arr[105][105];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intM;
	cin >> intN >> intM;

	ll intMinX = 105, intMaxX = -1, intMinY = 105, intMaxY = -1;
	char c;
	ll intCount = 0;
	for (ll intI = 0; intI < intN; intI++)
	{
		for (ll intJ = 0; intJ < intM; intJ++)
		{
			cin >> c;
			if (c == 'W')
			{
				arr[intI][intJ] = 0;
			}
			else
			{
				arr[intI][intJ] = 1;
				intMinX = min(intMinX, intJ);
				intMinY = min(intMinY, intI);
				intMaxX = max(intMaxX, intJ);
				intMaxY = max(intMaxY, intI);
				intCount++;
			}
		}
	}

	ll intSide = max((intMaxX - intMinX), (intMaxY - intMinY)) + 1;
	if (intSide > intM ||
		intSide > intN)
	{
		cout << -1 << endl;
	}
	else if (intCount == 0)
	{
		cout << 1 << endl;
	}
	else
	{
		cout << intSide * intSide - intCount << endl;
	}

	return 0;
}
//======================================================================================================================