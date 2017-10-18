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
	ll intV, intE;
	ll intSum = 0;

	cin >> intV >> intE;
	FOR(intI, 0, intV)
	{
		cin >> arr[intI];
	}

	ll intS, intD;
	FOR(intI, 0, intE)
	{
		cin >> intS >> intD;
		intS--; intD--;
		intSum += min(arr[intS], arr[intD]);
	}

	cout << intSum << endl;

	return 0;
}

//======================================================================================================================