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
#include <climits>
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
ll arr[1000005];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intT, intN;
	scanf("%lld", &intT);
	vi v;
	while (intT--)
	{
		scanf("%lld", &intN);

		FOR(intI, 0, intN)
		{
			scanf("%lld", &arr[intI]);
		}

		v.clear();
		FOR(intI, 0, intN)
		{
			if (v.size() > 0 && arr[intI] < v[v.size() - 1])
			{
				auto it = lower_bound(v.begin(), v.end(), arr[intI]);
				if (it - v.begin() >= v.size())
				{
					v.pb(arr[intI]);
				}
				else
				{
					v[it - v.begin()] = arr[intI];
				}
			}
			else
			{
				v.pb(arr[intI]);
			}
		}

		ll intL;
		scanf("%lld", &intL);
		if (intL > v.size())
		{
			printf("-1\n");
		}
		else
		{
			printf("%lld\n", v[intL - 1]);
		}
	}
	return 0;
}
//======================================================================================================================