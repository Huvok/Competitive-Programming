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
typedef pair<int, int> ii;
typedef vector<ii> vii;

//======================================================================================================================
ll arr[25];

ll intGetN(ll intD, ll intK)
{
	ll intCur = 0;
	ll intN = 1;
	ll intPrevious;
	while (true)
	{
		intPrevious = intCur;
		intCur += intN * intD;
		if (intPrevious < intK &&
			intCur >= intK)
		{
			return intN;
		}
		else
		{
			intN++;
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intT;
	cin >> intT;

	while (intT--)
	{
		ll intCi;
		cin >> intCi;

		for (ll intI = 0; intI <= intCi; intI++)
		{
			cin >> arr[intI];
		}
		
		ll intD, intK;
		cin >> intD;
		cin >> intK;

		ll intN = intGetN(intD, intK);

		ll intRes = 0;
		ll intCur = 0;
		for (ll intI = 0; intI <= intCi; intI++)
		{
			intRes += arr[intI] * pow(intN, intCur);
			intCur++;
		}

		cout << intRes << endl;
	}

	return 0;
}
//======================================================================================================================