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
#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define pb push_back
#define mp make_pair
#define lld I64d

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
ll arr[100000005];

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll intT, intN, intP;

	scanf("%lld", &intT);

	while (intT--)
	{
		scanf("%lld %lld", &intN, &intP);
		ll a = 0, b = 0;
		FOR(intI, 0, intN)
		{
			scanf("%lld", &arr[intI]);
		}

		FOR(intI, 0, intN)
		{
			if (arr[intI] <= intP / 10)
			{
				b++;
			}
			else if (arr[intI] >= intP / 2)
			{
				a++;
			}
		}

		if (a == 1 && b == 2)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}

	return 0;
}

//======================================================================================================================