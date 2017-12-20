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
ll segmentTree[100005 * 4], lazy[100005 * 4];
ll intN, intM;

void propagate(ll n)
{
	lazy[n << 1] += lazy[n];
	lazy[n << 1 | 1] += lazy[n];
	segmentTree[n << 1] += lazy[n];
	segmentTree[n << 1 | 1] += lazy[n];
	lazy[n] = 0;
}

void precalcSegmentTree(ll n, ll l, ll r)
{
	if (l == r)
	{
		segmentTree[n] = arr[l - 1];
	}
	else
	{
		ll m = ((r - l) >> 1) + l;
		precalcSegmentTree(n << 1, l, m);
		precalcSegmentTree(n << 1 | 1, m + 1, r);

		propagate(n);
		segmentTree[n] = max(segmentTree[n << 1], segmentTree[n << 1 | 1]);
	}
}

ll kth(ll n, ll l, ll r, ll x)
{
	if (x < l ||
		r < x)
		return -1e9;

	if (l == r)
		return segmentTree[n];

	propagate(n);
	ll m = ((r - l) >> 1) + l;
	return max(kth(n << 1, l, m, x), kth(n << 1 | 1, m + 1, r, x));
}

ll getLast(ll n, ll l, ll r, ll v)
{
	if (l == r)
		return l;

	propagate(n);
	ll m = ((r - l) >> 1) + l;

	if (segmentTree[n << 1 | 1] >= v)
		return getLast(n << 1 | 1, m + 1, r, v);
	else
		return getLast(n << 1, l, m, v);
}

void update(ll n, ll l, ll r, ll last, ll lastP1, ll v)
{
	if (last <= l &&
		r <= lastP1)
	{
		lazy[n] += v;
		segmentTree[n] += v;
		return;
	}
	
	if (r < last ||
		lastP1 < l)
		return;

	ll m = ((r - l) >> 1) + l;
	update(n << 1, l, m, last, lastP1, v);
	update(n << 1 | 1, m + 1, r, last, lastP1, v);
	propagate(n);
	segmentTree[n] = max(segmentTree[n << 1], segmentTree[n << 1 | 1]);
}

ll findLast(ll v)
{
	if (segmentTree[1] < v)
		return 0;

	return getLast(1, 1, intN, v);
}

bool query(ll x)
{
	ll v = kth(1, 1, intN, x);

	if (v == 0)
		return false;

	ll last, lastP1;
	lastP1 = findLast(v);
	last = findLast(v + 1);

	ll left = x - last;

	if (last >= 1)
		update(1, 1, intN, 1, last, -1);

	if (lastP1 >= lastP1 - left + 1)
		update(1, 1, intN, lastP1 - left + 1, lastP1, -1);
	
	return true;
}


//----------------------------------------------------------------------------------------------------------------------

int main()
{
	cin >> intN >> intM;

	FOR(intI, 0, intN)
	{
		cin >> arr[intI];
	}

	sort(arr, arr + intN);
	reverse(arr, arr + intN);

	precalcSegmentTree(1, 1, intN);

	FOR(intI, 0, intM)
	{
		ll x;
		scanf("%lld", &x);

		if (x > intN)
		{
			printf("%lld\n", intI);
			break;
		}
		else
		{
			if (!query(x))
			{
				printf("%lld\n", intI);
				break;
			}
		}

		if (intI == intM - 1)
		{
			printf("%lld\n", intM);
		}
	}

	return 0;
}

//======================================================================================================================