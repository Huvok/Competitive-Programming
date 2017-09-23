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
ll arr[100000], arrTest[100000];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intM;
	cin >> intN >> intM;
	ll intLastPile = 0;

	ll intBoxes = 0;
	FOR(intI, 0, intN)
	{
		cin >> arr[intI];
		intBoxes += arr[intI];
	}

	ll intL = 2, intR = intN + intBoxes, intMiddle;

	ll intTimeLeft, intPrevMid = intR, intCurBoxes;
	while (intL < intR)
	{
		intMiddle = (intR - intL) / 2 + intL;
		intLastPile = intN - 1;
		FOR(intI, 0, intN) arrTest[intI] = arr[intI];
		for (int intI = 0; intI < intM; intI++)
		{
			while (intLastPile >= 0 &&
				arrTest[intLastPile] == 0) intLastPile--;
			intTimeLeft = intMiddle - intLastPile - 1;
			if (intTimeLeft <= 0) break;
			while (intLastPile >= 0 &&
				arrTest[intLastPile] <= intTimeLeft)
			{
				intTimeLeft -= arrTest[intLastPile--];
			}

			if (intLastPile >= 0) arrTest[intLastPile] -= intTimeLeft;
		}

		if (intLastPile < 0)
		{
			intR = intMiddle;
		}
		else
		{
			intL = intMiddle + 1;
		}
	}

	cout << intR << endl;

	return 0;
}
//======================================================================================================================