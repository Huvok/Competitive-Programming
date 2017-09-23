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

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
ll arr[100005];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intK;
	cin >> intN >> intK;

	FOR(intI, 0, intN)
	{
		cin >> arr[intI];
	}

	ll intL = 0, intR = 0;
	ll intRes = 0;
	ll intPrev = -1;

	while (intR < intN)
	{
		ll intCur = 1;
		FOR(intI, intL, intN)
		{
			intCur *= arr[intI];
			intCur %= intK;
			if (!intCur)
			{
				intR = intI;
				break;
			}
		}

		if (intCur) break;
		intCur = 1;
		for (ll intI = intR; intI >= 0; intI--)
		{
			intCur *= arr[intI];
			intCur %= intK;
			intCur %= intK;
			if (!intCur)
			{
				intL = intI;
				break;
			}
		}

		if (!intCur)
		{
			intRes += (intL - intPrev) * (intN - intR);
			intPrev = intL;
			intL++;
			intR++;
		}
	}

	cout << intRes << endl;

	return 0;
}
//======================================================================================================================