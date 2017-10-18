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
vi lucky;

void generate(ll n)
{
	if (n >= 1e11) return;
	lucky.pb(n);
	generate(n * 10 + 4);
	generate(n * 10 + 7);
}
//----------------------------------------------------------------------------------------------------------------------
int main()
{
	generate(0);
	sort(lucky.begin(), lucky.end());

	ll l, r;
	cin >> l >> r;
	ll intSum = 0;
	while (l <= r)
	{
		auto it = lower_bound(lucky.begin(), lucky.end(), l) - lucky.begin();
		intSum += (min(lucky[it], r) - l + 1) * lucky[it];
		l = min(lucky[it] + 1, r + 1);
	}

	cout << intSum << endl;

	return 0;
}
//======================================================================================================================