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
ll arr[100005];
ll err[100005];
set<ll> s;

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intM;
	scanf("%lld %lld", &intN, &intM);

	FOR(intI, 0, intN)
	{
		scanf("%lld", &arr[intI]);
	}

	for (ll i = intN - 1; i >= 0; i--)
	{
		if (s.find(arr[i]) == s.end())
		{
			err[i] = s.size() + 1;
			s.insert(arr[i]);
		}
		else
		{
			err[i] = s.size();
		}
	}

	ll intNext;
	FOR(intI, 0, intM)
	{
		scanf("%lld", &intNext);
		printf("%lld\n", err[intNext - 1]);
	}
	return 0;
}
//======================================================================================================================