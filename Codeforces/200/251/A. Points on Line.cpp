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
ll arr[100005];

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll n, k;
	scanf("%lld %lld", &n, &k);

	FOR(i, 0, n)
	{
		scanf("%lld", &arr[i]);
	}

	ll l = 0, r = 0;
	ll ans = 0;
	while (r < n)
	{
		while (arr[r] - arr[l] > k)
		{
			l++;
		}
		
		if (r - l + 1 >= 3)
		{
			ans += ((r - l) * (r - l - 1)) / 2;
		}

		r++;
	}

	printf("%lld\n", ans);

	return 0;
}

//====================================================================================================================== 