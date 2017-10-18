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
bool cmp(ll i, ll j) 
{
	return i > j;
}

ll arr[105];

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll intN;
	cin >> intN;
	FOR(intI, 0, intN) cin >> arr[intI];

	sort(arr, arr + intN, cmp);
	sort(arr + 1, arr + intN - 1);

	FOR(intI, 0, intN) cout << arr[intI] << " ";
	cout << endl;

	return 0;
}

//======================================================================================================================