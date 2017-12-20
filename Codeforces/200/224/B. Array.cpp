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
unordered_map<ll, ll> m;

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll n, k;
	scanf("%lld %lld", &n, &k);

	FOR(i, 0, n)
	{
		scanf("%lld", &arr[i]);
		m[arr[i]]++;
	}

	ll l = 0, r = n - 1;
	ll count = m.size();
	if (m.size() < k)
	{
		printf("-1 -1\n");
	}
	else
	{
		while (count >= k)
		{
			m[arr[r]]--;
			if (m[arr[r]] == 0)
				count--;
			r--;
		}

		ll champ = INT_MAX;
		ll ansL, ansR;

		while (r < n)
		{
			while (count < k)
			{
				r++;
				if (m[arr[r]] == 0)
					count++;
				m[arr[r]]++;
			}

			if (r >= n)
				break;

			while (count >= k)
			{
				m[arr[l]]--;
				if (m[arr[l]] == 0)
					count--;
				l++;
			}

			if ((r - l + 2) < champ)
			{
				champ = (r - l + 2);
				ansL = l - 1;
				ansR = r;
			}
		}

		printf("%lld %lld\n", ansL + 1, ansR + 1);
	}

	return 0;
}

//====================================================================================================================== 