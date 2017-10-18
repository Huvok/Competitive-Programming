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
ll arr[1005];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll l = -INT_MAX, h = INT_MAX;

	ll intN;
	cin >> intN;

	FOR(intI, 0, intN) cin >> arr[intI];

	FOR(intI, 1, intN)
	{
		FOR(intJ, 1, intN)
		{
			if (abs(intI - intJ) <= 1) continue;
			ll x1 = min(arr[intI - 1], arr[intI]);
			ll x2 = max(arr[intI - 1], arr[intI]);
			ll x3 = min(arr[intJ - 1], arr[intJ]);
			ll x4 = max(arr[intJ - 1], arr[intJ]);
			if (x1 < x3 &&
				x3 < x2 &&
				x2 < x4)
			{
				cout << "yes" << endl;
				return 0;
			}
		}
	}

	cout << "no" << endl;
	return 0;
}

//======================================================================================================================