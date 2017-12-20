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
#include <limits.h>

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
#define ifile(a) freopen((a), "r", stdin)
#define ofile(a) freopen((a), "w", stdout)
#define sync ios_base::sync_with_stdio(false)

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

using namespace std;

//----------------------------------------------------------------------------------------------------------------------
ll arr[100005], ans[100005];

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll intT, intN;
	scanf("%lld", &intT);

	while (intT--)
	{
		scanf("%lld", &intN);

		FOR(intI, 0, intN)
		{
			scanf("%lld", &arr[intI]);
			ans[intI] = arr[intI];
		}

		FOR(intI, 0, intN - 1)
		{
			if (ans[intI] == arr[intI])
			{
				swap(ans[intI], ans[intI + 1]);

				if (ans[intI] == arr[intI])
				{
					if (intI)
						swap(ans[intI], ans[intI - 1]);
					else if (intI < intN - 2)
						swap(ans[intI], ans[intN - 1]);
				}
			}
		}

		if (ans[intN - 1] == arr[intN - 1] &&
			intN > 1 &&
			ans[intN - 1] == arr[intN - 2])
		{
			swap(ans[intN - 1], ans[0]);
		}
		else if (ans[intN - 1] == arr[intN - 1] &&
			intN > 1)
			swap(ans[intN - 1], ans[intN - 2]);
		ll sum = 0;
		FOR(intI, 0, intN)
		{
			if (ans[intI] != arr[intI])
				sum++;
		}

		printf("%lld\n", sum);

		FOR(intI, 0, intN)
		{
			printf("%lld ", ans[intI]);
		}

		printf("\n");
	}
	return 0;
}

//======================================================================================================================