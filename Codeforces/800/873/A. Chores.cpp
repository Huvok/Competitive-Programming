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
ll arr[105];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intK, intX;
	cin >> intN >> intK >> intX;
	FOR(intI, 0, intN) cin >> arr[intI];

	ll intSum = 0;
	for (ll i = intN - 1; i >= 0; i--)
	{
		if (intK)
		{
			intSum += intX;
			intK--;
		}
		else
		{
			intSum += arr[i];
		}
	}

	cout << intSum << endl;

	return 0;
}

//======================================================================================================================