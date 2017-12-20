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
ll arr[100005], intN, intK;

struct Node 
{
	ll validCum, val, kthValid, pos;

	Node()
	{
		validCum = 0;
		val = -1;
		kthValid = 0;
		pos = -1;
	}

	Node(ll val, ll pos)
	{
		this->validCum = 1;
		this->val = val;
		this->kthValid = 0;
		this->pos = pos;
	}
};

Node segmentTree[100005 * 4];


Node getMaxNode(Node a, Node b)
{
	Node node;
	node.validCum = a.validCum + b.validCum;

	if (a.val >= b.val)
	{
		node.pos = a.pos;
		node.kthValid = a.kthValid;
		node.val = a.val;
	}
	else
	{
		node.pos = b.pos;
		node.kthValid = b.kthValid + a.validCum;
		node.val = b.val;
	}

	return node;
}

void precalcSegmentTree(ll n, ll l, ll r)
{
	if (l == r)
	{
		segmentTree[n] = Node(arr[l], l);
		return;
	}

	ll m = ((r - l) >> 1) + l;
	precalcSegmentTree(n << 1, l, m);
	precalcSegmentTree(n << 1 | 1, m + 1, r);
	segmentTree[n] = getMaxNode(segmentTree[n << 1], segmentTree[n << 1 | 1]);
}

Node kth(ll n, ll l, ll r, ll k)
{
	if (k < 0)
	{
		return Node();
	}

	if (segmentTree[n].kthValid <= k)
		return segmentTree[n];

	ll m = ((r - l) >> 1) + l;
	return getMaxNode(kth(n << 1, l, m, k),
		kth(n << 1 | 1, m + 1, r, k - segmentTree[n << 1].validCum));
}

void eraseElement(ll n, ll l, ll r, ll pos)
{
	if (pos < l)
		return;
	if (r < pos)
		return;

	if (l == r)
	{
		segmentTree[n] = Node();
		return;
	}

	ll m = ((r - l) >> 1) + l;
	eraseElement(n << 1, l, m, pos);
	eraseElement(n << 1 | 1, m + 1, r, pos);
	segmentTree[n] = getMaxNode(segmentTree[n << 1], segmentTree[n << 1 | 1]);
}

ll kth()
{
	Node node = kth(1, 0, intN - 1, intK);
	eraseElement(1, 0, intN - 1, node.pos);
	intK -= node.kthValid;

	return node.val;
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	scanf("%lld %lld", &intN, &intK);

	FOR(intI, 0, intN)
	{
		scanf("%lld", &arr[intI]);
	}

	precalcSegmentTree(1, 0, intN - 1);

	vi ans;
	FOR(i, 0, intN)
	{
		ans.pb(kth());
	}

	FOR(i, 0, ans.size())
	{
		printf("%lld ", ans[i]);
	}

	printf("\n");

	return 0;
}

//======================================================================================================================