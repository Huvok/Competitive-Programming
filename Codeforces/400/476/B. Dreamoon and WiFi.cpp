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
	ll intP = 0, intM = 0, intIn = 0;
	string s;
	cin >> s;
	FOR(intI, 0, s.length())
	{
		if (s[intI] == '+') intP++;
	}

	cin >> s;
	FOR(intI, 0, s.length())
	{
		if (s[intI] == '+') intP--;
		else if (s[intI] == '?') intIn++;
	}

	ll N = 1, K = 1;
	FOR(intI, 1, intIn + 1)
	{
		N *= intI;
	}

	if (intP < 0)
	{
		printf("%.12f\n", 0.0);
	}
	else if (intP == 0 && intIn == 0)
	{
		printf("%.12f\n", 1.0);
	}
	else
	{
		ll NMK = intIn - intP;
		for (ll i = NMK - 1; i >= 1; i--)
		{
			NMK *= i;
		}

		FOR(intI, 1, intP + 1)
		{
			K *= intI;
		}

		ll NK;
		if (intIn == intP) NK = 1;
		else NK = N / (NMK * K);

		printf("%.12f\n", (NK <= 0 ? 0.0 : NK * 1.0 / (pow(2, intIn))));
	}

	return 0;
}

//======================================================================================================================