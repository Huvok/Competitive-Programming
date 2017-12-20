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

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll n, m, k;

	scanf("%lld %lld %lld", &n, &m, &k);
	ll idx = 1;
	ll jdx = 1;
	bool going = true;
	while (k > 1)
	{
		printf("2 ");
		if ((jdx < m && going) ||
			(jdx > 1 && !going))
		{
			printf("%lld %lld ", idx, jdx);
			if (going)
			{
				jdx++;
			}
			else
			{
				jdx--;
			}

			printf("%lld %lld ", idx, jdx);

			if (jdx == m)
			{
				idx++;
				going = false;
			}
			else if (jdx == 1)
			{
				idx++;
				going = true;
			}
			else
			{
				if (going)
					jdx++;
				else
					jdx--;
			}
		}
		else
		{
			if (going)
			{
				printf("%lld %lld ", idx, jdx);
				idx++;
				printf("%lld %lld ", idx, jdx);
				jdx--;
				going = false;
			}
			else
			{
				printf("%lld %lld ", idx, jdx);
				idx++;
				printf("%lld %lld ", idx, jdx);
				jdx++;
				going = true;
			}
		}

		k--;
		printf("\n");
	}

	printf("%lld ", (n - idx) * m + (going ? m - jdx + 1 : jdx));
	FOR(i, idx, n + 1)
	{
		if (going)
		{
			FOR(j, jdx, m + 1)
			{
				printf("%lld %lld ", i, j);
				jdx++;
			}
		}
		else
		{
			RFOR(j, jdx, 1)
			{
				printf("%lld %lld ", i, j);
				jdx--;
			}
		}

		if (jdx == 0)
			jdx++;
		else
			jdx--;

		going = !going;
	}

	printf("\n");

	return 0;
}

//====================================================================================================================== 