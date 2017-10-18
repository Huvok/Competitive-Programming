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
	ll intN, intInit, intFin;
	cin >> intN >> intInit >> intFin;

	FOR(intI, 0, intN)
	{
		cin >> arr[intI];
	}

	ll intCount = 0;
	ll intCur = intInit;
	while (intCur != intFin)
	{
		intCount++;
		intCur = arr[intCur - 1];
		if (intCur == intInit)
		{
			cout << -1 << endl;
			return 0;
		}
	}

	cout << intCount << endl;

	return 0;
}

//======================================================================================================================