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
	ll a, b, c, x, y, z;
	cin >> a >> b >> c;

	FOR(intI, 0, 3000005)
	{
		x = intI;
		z = a - x;
		y = b - x;
		if (y + z == c &&
			y >= 0 && z >= 0)
		{
			cout << x << " " << y << " " << z << endl;
			break;
		}

		if (intI == 3000004)
		{
			cout << "Impossible" << endl;
		}
	}

	return 0;
}

//======================================================================================================================