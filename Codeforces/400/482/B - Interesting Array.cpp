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

using namespace std;

//															//AUTHOR: Hugo Garcia
//															//PURPOSE: Competitive programming template

//======================================================================================================================

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
pair<ii, ll> queries[100005];
ll dp[100005], arr[100005];
ll intN;

ll segmentTree[3 * 100005], ss;

void precalcSegmentTree()
{
	FOR(intI, 0, ss)
	{
		segmentTree[ss + intI] = 0;
	}

	FOR(intI, 0, intN)
	{
		segmentTree[ss + intI] = arr[intI];
	}

	for (ll intI = ss - 1; intI; intI--)
	{
		segmentTree[intI] = segmentTree[intI << 1] & segmentTree[intI << 1 | 1];
	}
}

ll query(ll n, ll l, ll r, ll d)
{
	if (l > r) return (1LL << 31) - 1;

	if (!l && r == d - 1) {
		return segmentTree[n];
	}

	d /= 2;

	ll a = query(n << 1, l, min(d - 1, r), d);
	ll b = query(2 * n + 1, max(0LL, l - d), r - d, d);

	return a & b;
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intM, intL, intR, intQ;
	scanf("%lld %lld", &intN, &intM);

	FOR(intI, 0, intM)
	{
		scanf("%lld %lld %lld", &queries[intI].first.first, &queries[intI].first.second,
			&queries[intI].second);
	}

	FOR(intI, 0, intM) queries[intI].first.first--;
	FOR(intI, 0, 31)
	{
		memset(dp, 0, sizeof(dp));
		FOR(intJ, 0, intM)
		{
			if (queries[intJ].second & (1LL << intI))
			{
				dp[queries[intJ].first.first]++;
				dp[queries[intJ].first.second]--;
			}
		}

		FOR(intJ, 0, intN)
		{
			if (intJ)
			{
				dp[intJ] += dp[intJ - 1];
			}

			if (dp[intJ] > 0)
			{
				arr[intJ] |= (1 << intI);
			}
		}
	}

	ss = 1 << (int)ceil(log2(intN));
	precalcSegmentTree();

	FOR(intI, 0, intM)
	{
		if (query(1, queries[intI].first.first, queries[intI].first.second - 1, ss) !=
			queries[intI].second)
		{
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");
	FOR(intI, 0, intN)
	{
		printf("%lld", arr[intI]);
		if (intI != intN - 1)
		{
			printf(" ");
		}
	}

	printf("\n");

	return 0;
}
//======================================================================================================================