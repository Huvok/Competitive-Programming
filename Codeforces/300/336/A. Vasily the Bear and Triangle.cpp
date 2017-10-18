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
	ll intX, intY;
	cin >> intX >> intY;
	ll intVal = abs(intX) + abs(intY);

	ii f = mp(intVal * (intX < 0 ? -1 : 1), 0);
	ii s = mp(0, intVal * (intY < 0 ? -1 : 1));
	if (f.first > s.first) swap(f, s);

	cout << f.first << " " << f.second << " " << s.first << " " << s.second << endl;

	return 0;
}
//======================================================================================================================