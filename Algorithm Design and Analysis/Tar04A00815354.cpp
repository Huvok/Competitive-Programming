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

using namespace std;

//															//AUTHOR: Hugo Garcia
//															//PURPOSE: Competitive programming template

//======================================================================================================================

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
bitset<105005> bs;

void sieve()
{
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= 105000; i++)
	{
		if (bs[i])
		{
			for (ll j = i * i; j <= 105000; j += i)
			{
				bs[j] = 0;
			}
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	sieve();
	ll intN, intX;
	cin >> intN;

	FOR(intI, 0, intN)
	{
		cin >> intX;
		ll intL = intX, intR = intX;

		while (!bs[intL]) intL--;
		while (!bs[intR]) intR++;

		cout << intL << " " << intR << endl;
	}

	return 0;
}
//======================================================================================================================