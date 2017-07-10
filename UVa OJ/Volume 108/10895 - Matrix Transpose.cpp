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
ll arr[10005][10005];
ll arrNonZero[10005];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intM;

	while (scanf("%lld %lld", &intN, &intM) == 2)
	{
		ll intCol;
		memset(arr, 0, sizeof arr);
		for (ll intI = 0; intI < intN; intI++)
		{
			cin >> intCol;

			if (intCol == 0) continue;

			for (ll intJ = 0; intJ < intCol; intJ++)
			{
				cin >> arrNonZero[intJ];
			}

			for (ll intJ = 0; intJ < intCol; intJ++)
			{
				cin >> arr[intI][arrNonZero[intJ] - 1];
			}
		}

		cout << intM << " " << intN << endl;
		for (ll intJ = 0; intJ < intM; intJ++)
		{
			ll intCount = 0;
			for (ll intI = 0; intI < intN; intI++)
			{
				if (arr[intI][intJ] != 0)
				{
					arrNonZero[intCount] = intI;
					intCount++;
				}
			}

			cout << intCount;
			if (intCount == 0)
			{
				cout << endl; 
				cout << endl;
				continue;
			}
			else
			{
				cout << " ";
			}

			for (ll intI = 0; intI < intCount; intI++)
			{
				cout << arrNonZero[intI] + 1;
				if (intI != intCount - 1) cout << " ";
			}

			cout << endl;

			for (ll intI = 0; intI < intCount; intI++)
			{
				cout << arr[arrNonZero[intI]][intJ];
				if (intI != intCount - 1) cout << " ";
			}

			cout << endl;
		}
	}
	
	return 0;
}
//======================================================================================================================