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
ii arr[100005];

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll n, r, avg;
	scanf("%lld %lld %lld", &n, &r, &avg);

	ll cur = 0;
	FOR(i, 0, n)
	{
		scanf("%lld %lld", &arr[i].second, &arr[i].first);
		cur += arr[i].second;
	}

	sort(arr, arr + n);
	ll ans = 0;
	
	ll idx = 0;
	
	if (cur * 1.0 / n < avg)
	{
		while (idx < n)
		{
			if (cur * 1.0 / n >= avg)
				break;

			if ((cur + (r - arr[idx].second) * 1.0) / n >= avg)
			{
				ans += ((avg * n - cur) * arr[idx].first);
				cur += (avg * n - cur);
			}
			else
			{
				cur += (r - arr[idx].second);
				ans += ((r - arr[idx].second) * arr[idx].first);
			}

			if (cur * 1.0 / n >= avg)
				break;

			idx++;
		}
	}

	printf("%lld\n", ans);

	return 0;
}

//====================================================================================================================== 