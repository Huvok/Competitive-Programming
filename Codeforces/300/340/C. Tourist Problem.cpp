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
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

using namespace std;

//----------------------------------------------------------------------------------------------------------------------
ll arr[100005];

ll gcd(ll a, ll b)
{
	if (!b)
		return a;
	return gcd(b, a % b);
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll n;
	scanf("%lld", &n);
	ll sum = 0;
	FOR(i, 0, n)
	{
		scanf("%lld", &arr[i]);
		sum += arr[i];
	}

	sort(arr, arr + n);
	ll diffs = 0;
	ll dp = arr[0];
	FOR(i, 1, n)
	{
		diffs += (i * arr[i] - dp);
		dp += arr[i];
	}

	sum += 2 * diffs;
	ll _gcd = gcd(sum, n);

	printf("%lld %lld\n", sum / _gcd, n / _gcd);

	return 0;
}

//====================================================================================================================== 