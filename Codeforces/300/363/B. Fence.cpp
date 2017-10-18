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
ll arr[200005];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intK;
	cin >> intN >> intK;

	FOR(intI, 0, intN) cin >> arr[intI];
	FOR(intI, 1, intN) arr[intI] = arr[intI] + arr[intI - 1];
	ll intChamp = INT_MAX;
	ll intIndex = 0;
	FOR(intI, intK - 1, intN)
	{
		if (arr[intI] - (intI - intK >= 0 ? arr[intI - intK] : 0) < intChamp)
		{
			intChamp = arr[intI] - (intI - intK >= 0 ? arr[intI - intK] : 0);
			intIndex = intI - intK + 2;
		}
	}

	cout << intIndex << endl;

	return 0;
}

//======================================================================================================================