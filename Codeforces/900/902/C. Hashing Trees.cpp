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
ll arr[300005];

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll h;
	scanf("%lld", &h);

	FOR(i, 0, h + 1)
	{
		scanf("%lld", &arr[i]);
	}

	bool can = true;
	FOR(i, 1, h + 1)
	{
		if (arr[i] != 1 &&
			arr[i - 1] != 1)
		{
			can = false;
			break;
		}
	}

	if (can)
	{
		printf("perfect\n");
	}
	else
	{
		ll last = 0;
		printf("ambiguous\n");
		printf("0 ");
		ll cur = 1;
		FOR(i, 1, h + 1)
		{
			FOR(j, 0, arr[i])
			{
				if (arr[i] > 1 &&
					arr[i - 1] > 1 &&
					last == 0)
					last = i;
				printf("%lld ", cur);
			}

			cur += arr[i - 1];
		}

		printf("\n");
		printf("0 ");
		cur = 1;
		FOR(i, 1, h + 1)
		{
			FOR(j, 0, arr[i])
			{
				if (i == last &&
					j == arr[i] - 1)
				{
					printf("%lld ", cur + 1);
				}
				else
					printf("%lld ", cur);
			}

			cur += arr[i - 1];
		}
	}

	return 0;
}

//====================================================================================================================== 