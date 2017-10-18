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
	ll intN, intK;
	cin >> intN >> intK;

	ll intIndex = 0;
	FOR(intI, 0, intN)
	{
		cin >> arr[intI];
	}

	ll intSum = 0;
	ll i = 0;
	while (intK > 0 && arr[i] < 0)
	{
		arr[i] *= -1;
		i++;
		intK--;
	}

	sort(arr, arr + intN);

	while (intK > 0)
	{
		arr[0] *= -1;
		intK--;
	}

	FOR(intI, 0, intN)
	{
		intSum += arr[intI];
	}

	cout << intSum << endl;

	return 0;
}

//======================================================================================================================