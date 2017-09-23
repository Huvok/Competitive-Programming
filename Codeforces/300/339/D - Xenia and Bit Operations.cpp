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
int segmentTree[3 * 131072], lazy[3 * 131072], ss;

ll a[131072];

void precalcSegmentTree(int N) {
	FOR(i, 0, ss) segmentTree[ss + i] = 0;
	FOR(i, 0, N) {
		segmentTree[ss + i] = a[i];
	}

	bool x = false;
	ll intLeft = N >> 1;
	ll intNext = intLeft >> 1;
	for (int i = ss - 1; i; i--) {
		if (x) segmentTree[i] = segmentTree[i << 1] ^ segmentTree[i << 1 | 1];
		else segmentTree[i] = segmentTree[i << 1] | segmentTree[i << 1 | 1];
		intLeft--;
		if (intLeft == 0)
		{
			x = !x;
			intLeft = intNext;
			intNext = intNext >> 1;
		}
	}
}

void modify(int n, int x, bool xo) {
	segmentTree[n] = x;
	while (n >>= 1) {
		if (xo)
		{
			segmentTree[n] = segmentTree[n << 1] ^ segmentTree[n << 1 | 1];
		}
		else
		{
			segmentTree[n] = segmentTree[n << 1] | segmentTree[n << 1 | 1];
		}
		
		xo = !xo;
	}
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intM;
	cin >> intN >> intM;
	ss = 1 << intN;
	FOR(intI, 0, pow(2, intN)) cin >> a[intI];
	precalcSegmentTree(pow(2, intN));
	ll intIndex, intVal;
	FOR(intI, 0, intM)
	{
		scanf("%lld %lld", &intIndex, &intVal);
		modify(intIndex + pow(2, intN) - 1, intVal, false);
		printf("%lld\n", segmentTree[1]);
	}

	return 0;
}
//======================================================================================================================