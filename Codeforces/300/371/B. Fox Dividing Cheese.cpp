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
	ll a2 = 0, a3 = 0, a5 = 0, b2 = 0, b3 = 0, b5 = 0;

	ll a, b;
	cin >> a >> b;
	while (a % 2 == 0) a2++, a /= 2;
	while (a % 3 == 0) a3++, a /= 3;
	while (a % 5 == 0) a5++, a /= 5;
	while (b % 2 == 0) b2++, b /= 2;
	while (b % 3 == 0) b3++, b /= 3;
	while (b % 5 == 0) b5++, b /= 5;

	if (a == b)
		cout << abs(a2 - b2) + abs(a3 - b3) + abs(a5 - b5) << endl;
	else
		cout << -1 << endl;

	return 0;
}

//======================================================================================================================