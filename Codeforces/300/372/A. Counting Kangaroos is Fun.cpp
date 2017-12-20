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
ll arr[500005];

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll n;
	scanf("%lld", &n);

	FOR(i, 0, n)
		scanf("%lld", &arr[i]);

	sort(arr, arr + n);

	ll i = 0, j = n / 2;
	ll ans = n;
	while (j < n)
	{
		if (arr[i] * 2 <= arr[j])
		{
			ans--;
			i++;
		}

		j++;
	}

	printf("%lld\n", max((n  + 1)/ 2, ans));

	return 0;
}

//====================================================================================================================== 