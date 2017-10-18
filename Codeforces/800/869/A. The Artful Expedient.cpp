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
ll arr1[2005], arr2[2005];
unordered_set<ll> s;

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN;
	scanf("%lld", &intN);

	FOR(intI, 0, intN)
	{
		scanf("%lld", &arr1[intI]);
		s.insert(arr1[intI]);
	}

	FOR(intI, 0, intN)
	{
		scanf("%lld", &arr2[intI]);
		s.insert(arr2[intI]);
	}

	ll intCount = 0;
	FOR(intI, 0, intN)
	{
		FOR(intJ, 0, intN)
		{
			if (s.find(arr1[intI] ^ arr2[intJ]) != s.end())
			{
				intCount++;
			}
		}
	}

	if (intCount % 2 == 0)
	{
		printf("Karen\n");
	}
	else
	{
		printf("Koyomi\n");
	}

	return 0;
}

//======================================================================================================================