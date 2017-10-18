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
ll arr[100005];

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll intL, intR, intN;

	scanf("%lld", &intN);

	FOR(intI, 0, intN) scanf("%lld", &arr[intI]);

	ll intChamp = 0;
	bool cool = true;
	intL = 0; intR = 0;

	while (intR < intN)
	{
		while (cool && intR < intN)
		{
			if (intR - intL >= 2)
			{
				if (arr[intR] == arr[intR - 1] + arr[intR - 2])
				{
					intR++;
				}
				else cool = false;
			}
			else intR++;
		}

		intChamp = max(intChamp, intR - intL);

		cool = true;
		intL = intR - 1;
	}

	printf("%lld\n", intChamp);

	return 0;
}

//======================================================================================================================