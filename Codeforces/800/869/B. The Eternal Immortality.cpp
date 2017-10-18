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
	ll a, b;

	cin >> a >> b;
	if (!a && !b ||
		(a == b))
	{
		cout << 1 << endl;
		return 0;
	}

	ll faca = a, facb = b;
	a %= 10;
	b %= 10;

	ll intDif = 1;
	for (ll i = facb - 1; i >= 0; i--)
	{
		b *= i;
		b %= 10;
		if (!b) break;
		intDif++;
	}

	if (facb - faca > intDif)
	{
		cout << 0 << endl;
	}
	else
	{
		b = facb % 10;
		for (ll i = facb - 1; i > faca; i--)
		{
			if (b * i % 10 == 0) break;
			b *= i;
			b %= 10;
		}

		cout << b << endl;
	}

	return 0;
}
//======================================================================================================================