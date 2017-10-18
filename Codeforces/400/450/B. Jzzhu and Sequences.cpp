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

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll x, y, n;
	cin >> x >> y >> n;

	n--;
	n %= 6;

	ll arr[6];
	arr[0] = x;
	arr[1] = y;
	FOR(i, 2, 6)
	{
		arr[i] = arr[i - 1] - arr[i - 2];
	}

	while (arr[n] < 0) arr[n] = (arr[n] + 1000000007) % 1000000007;
	cout << arr[n] % 1000000007 << endl;
	
	return 0;
}

//======================================================================================================================