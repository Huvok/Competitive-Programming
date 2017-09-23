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
ll arr[1005];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN;
	cin >> intN;

	FOR(intI, 0, intN)
	{
		cin >> arr[intI];
	}

	ll intClicks = intN - arr[0];

	FOR(intI, 0, intN)
	{
		if (intI % 2 == 0)
		{
			if ((arr[intI] + intClicks) % intN != intI)
			{
				cout << "No" << endl;
				break;
			}
		}
		else
		{
			if (((arr[intI] - intClicks) + intN) % intN != intI)
			{
				cout << "No" << endl;
				break;
			}
		}

		if (intI == intN - 1)
		{
			cout << "Yes" << endl;
		}
	}

	return 0;
}
//======================================================================================================================