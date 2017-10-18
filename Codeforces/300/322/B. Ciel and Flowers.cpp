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
	ll r, g, b;
	cin >> r >> g >> b;

	ll intChamp = r / 3 + g / 3 + b / 3;
	r--;
	g--;
	b--;
	if (r >= 0 && g >= 0 && b >= 0) intChamp = max(intChamp, 1 + r / 3 + g / 3 + b / 3);
	r--; g--; b--;
	if (r >= 0 && g >= 0 && b >= 0) intChamp = max(intChamp, 2 + r / 3 + g / 3 + b / 3);
	cout << intChamp << endl;

	return 0;
}

//======================================================================================================================