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
map<ii, ll> dp;

ll intGetGrundy(ll i, ll mask, ll intMax)
{
	FOR(intI, mask, intMax)
	{
		if ((mask >> intI) & 1)
		{
			mask ^= (1LL << intI);
		}
	}

	if (dp.find(mp(i, mask)) != dp.end())
	{
		return dp[mp(i, mask)];
	}

	bool vis[61] = { false };
	FOR(intI, 0, i)
	{
		if ((mask >> intI) & 1)
		{
			vis[intGetGrundy(i - intI - 1, mask ^ (1LL << intI), i)] = true;
		}
	}

	FOR(intI, 0, 61)
	{
		if (!vis[intI])
		{
			dp.insert(mp(mp(i, mask), intI));
			return intI;
		}
	}
}

ll grundies[61];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN;
	scanf("%lld", &intN);
	ll intAns = 0;
	ll intNext;

	FOR(intI, 0, intN)
	{
		scanf("%lld", &intNext);
		intAns ^= intGetGrundy(intNext, (1LL << intNext) - 1, 61);
	}

	if (intAns)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
	}

	return 0;
}
//======================================================================================================================