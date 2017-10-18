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

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
ll arr[2005];

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll intN, intK;
	scanf("%lld %lld", &intN, &intK);

	FOR(intI, 0, intN) scanf("%lld", &arr[intI]);

	ll intCount = 0;
	FOR(intI, 0, intN)
	{
		if (arr[intI] + intK <= 5) intCount++;
	}

	printf("%lld\n", intCount / 3);

	return 0;
}
//======================================================================================================================