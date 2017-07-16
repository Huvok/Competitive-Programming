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
ll arr[1005];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intT, intN;
	cin >> intT;
	while (intT--)
	{
		cin >> intN;

		for (ll intI = 0; intI < intN; intI++)
		{
			cin >> arr[intI];
		}

		ll intSum = 0;
		for (ll intI = 1; intI < intN; intI++)
		{
			for (ll intJ = intI - 1; intJ >= 0; intJ--)
			{
				if (arr[intJ] <= arr[intI])
				{
					intSum++;
				}
			}
		}

		cout << intSum << endl;
	}

	return 0;
}
//======================================================================================================================