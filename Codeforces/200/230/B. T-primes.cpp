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
bool arr[5000005];

void sieve()
{
	memset(arr, true, sizeof(arr));

	arr[0] = arr[1] = false;

	FOR(intI, 2, 5000001)
	{
		if (arr[intI])
		{
			for (ll intJ = intI * 2; intJ < 5000001; intJ += intI)
			{
				arr[intJ] = false;
			}
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll intN;
	scanf("%lld", &intN);

	ll intNext;
	sieve();
	FOR(intI, 0, intN)
	{
		scanf("%lld", &intNext);
		ll i = sqrt(intNext);
		if (arr[(ll)sqrt(intNext)] && (ll)sqrt(intNext) * (ll)sqrt(intNext) == intNext) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}

//======================================================================================================================