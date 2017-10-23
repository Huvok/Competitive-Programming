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
#define RFOR(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define pb push_back
#define mp make_pair
#define lld I64d
#define all(a) (a).begin(), (a).end()

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
bool primes[200005];
ll mat[505][505];
vi ans;

void sieve()
{
	memset(primes, true, sizeof(primes));

	primes[0] = primes[1] = false;
	FOR(intI, 2, 200001)
	{
		if (primes[intI])
		{
			ans.pb(intI);
			for (ll intJ = intI * 2; intJ < 200001; intJ += intI)
			{
				primes[intJ] = false;
			}
		}
	}
}
//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll intN, intM;
	cin >> intN >> intM;
	sieve();
	FOR(intI, 0, intN)
	{
		FOR(intJ, 0, intM)
		{
			cin >> mat[intI][intJ];
		}
	}

	ll intChamp = INT_MAX;
	FOR(intI, 0, intN)
	{
		FOR(intJ, 0, intM)
		{
			auto it = lower_bound(all(ans), mat[intI][intJ]) - ans.begin();
			mat[intI][intJ] = ans[it] - mat[intI][intJ];
		}
	}

	ll intSum;
	FOR(intI, 0, intN)
	{
		intSum = 0;
		FOR(intJ, 0, intM)
		{
			intSum += mat[intI][intJ];
		}

		intChamp = min(intChamp, intSum);
	}

	FOR(intJ, 0, intM)
	{
		intSum = 0;
		FOR(intI, 0, intN)
		{
			intSum += mat[intI][intJ];
		}

		intChamp = min(intChamp, intSum);
	}

	cout << intChamp << endl;

	return 0;
}

//======================================================================================================================