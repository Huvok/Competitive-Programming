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
#include <unordered_set>

using namespace std;

//															//AUTHOR: Hugo Garcia
//															//PURPOSE: Competitive programming template

//======================================================================================================================

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define pb push_back
#define mp make_pair
#define lld I64d

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
ll arr[100005];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN;

	ll intSum = 0;
	cin >> intN;
	FOR(intI, 0, intN)
	{
		cin >> arr[intI];
		if (arr[intI] == intI) intSum++;
	}

	bool cool = false;
	FOR(intI, 0, intN)
	{
		if (arr[intI] != intI)
		{
			if (intI == arr[arr[intI]])
			{
				cool = true;
				break;
			}
		}
	}

	if (intSum == intN)
	{
		cout << intSum << endl;
	}
	else if (cool)
	{
		cout << intSum + 2 << endl;
	}
	else
	{
		cout << intSum + 1 << endl;
	}

	return 0;
}

//======================================================================================================================