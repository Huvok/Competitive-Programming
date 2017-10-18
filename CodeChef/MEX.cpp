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
ll arr[100005];
unordered_set<ll> m;

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll intT, intN, intK;

	scanf("%lld", &intT);
	while (intT--)
	{
		scanf("%lld %lld", &intN, &intK);
		m.clear();
		FOR(intI, 0, intN)
		{
			scanf("%lld", &arr[intI]);
			m.insert(arr[intI]);
		}

		sort(arr, arr + intN);

		ll intCur = -1;
		ll intAux = intK;
		FOR(intI, 0, intN * 2 + intAux)
		{
			if (m.find(intI) == m.end())
			{
				intCur = intI;
				intK--;
				if (intK < 0) break;
				m.insert(intI);
			}
		}

		printf("%lld\n", intCur);
	}

	return 0;
}

//======================================================================================================================