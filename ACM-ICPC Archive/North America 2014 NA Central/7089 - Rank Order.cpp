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
ii a[1000005], b[1000005];
//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll intN;
	ll intCase = 0;
	bool cool;
	while (scanf("%lld", &intN) == 1)
	{
		intCase++;
		FOR(intI, 0, intN) 
		{
			scanf("%lld", &a[intI].first);
			a[intI].second = intI;
		}

		FOR(intI, 0, intN)
		{
			scanf("%lld", &b[intI].first);
			b[intI].second = intI;
		}

		cool = true;
		sort(a, a + intN);
		sort(b, b + intN);

		reverse(a, a + intN);
		reverse(b, b + intN);

		ll intIndex = 0;
		FOR(intI, 0, intN)
		{
			if (a[intI].second != b[intI].second)
			{
				cool = false;
				intIndex = intI + 1;
				break;
			}
		}

		printf("Case %lld: ", intCase);
		if (cool)
		{
			printf("agree\n");
		}
		else
		{
			printf("%lld\n", intIndex);
		}
	}

	return 0;
}

//======================================================================================================================