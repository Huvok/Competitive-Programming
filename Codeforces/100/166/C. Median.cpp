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
ll arr[5005];

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll n, x;
	scanf("%lld %lld", &n, &x);

	bool is = false;
	FOR(i, 0, n)
	{
		scanf("%lld", &arr[i]);
		if (arr[i] == x)
			is = true;
	}

	ll ans = 0;
	if (!is)
	{
		arr[n] = x;
		n++;
		ans++;
	}

	sort(arr, arr + n);
	
	while (arr[(n - 1) / 2] != x)
	{
		if (arr[(n - 1) / 2] > x)
		{
			arr[n] = 1;
		}
		else
		{
			arr[n] = 1e5;
		}

		n++; 
		sort(arr, arr + n);
		ans++;
	}

	cout << ans << endl;

	return 0;
}

//====================================================================================================================== 