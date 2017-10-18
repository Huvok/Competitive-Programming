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
	ll a, b, c;
	cin >> a >> b;
	c = a + b;
	string sa, sb, sc;
	sa = to_string(a);
	sb = to_string(b);
	sc = to_string(c);
	string fa = "", fb = "", fc = "";
	FOR(intI, 0, sa.length())
	{
		if (sa[intI] != '0') fa += sa[intI];
	}

	FOR(intI, 0, sb.length())
	{
		if (sb[intI] != '0') fb += sb[intI];
	}

	FOR(intI, 0, sc.length())
	{
		if (sc[intI] != '0') fc += sc[intI];
	}

	ll aa, bb, cc;
	aa = atoi(fa.c_str());
	bb = atoi(fb.c_str());
	cc = atoi(fc.c_str());

	if (aa + bb == cc) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}
//======================================================================================================================