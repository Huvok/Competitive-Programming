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
	vi v1, v2, v3;
	ll intN;
	cin >> intN;
	ll intNext;

	FOR(intI, 0, intN)
	{
		cin >> intNext;

		if (intNext < 0) v1.pb(intNext);
		else if (intNext > 0) v2.pb(intNext);
		else v3.pb(intNext);
	}

	if (v1.size() % 2 == 0)
	{
		v3.pb(v1.back());
		v1.pop_back();
	}

	if (v2.size() == 0)
	{
		v2.pb(v1.back());
		v1.pop_back();
		v2.pb(v1.back());
		v1.pop_back();
	}

	cout << v1.size();
	FOR(intI, 0, v1.size()) cout << " " << v1[intI];
	cout << endl << v2.size();
	FOR(intI, 0, v2.size()) cout << " " << v2[intI];
	cout << endl << v3.size();
	FOR(intI, 0, v3.size()) cout << " " << v3[intI];
	cout << endl;

	return 0;
}
//======================================================================================================================