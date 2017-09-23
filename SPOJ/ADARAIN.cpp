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
int segmentTree[3 * 1000005], lazy[3 * 1000005], ss, a[1000005];

void precalcSegmentTree(int N) {
	// Reseteamos los valores y ponemos cosas ignorables
	memset(lazy, 0, sizeof(lazy));
	FOR(i, 0, ss) segmentTree[ss + i] = 0;
	// almacenamos las hojas
	FOR(i, 0, N) {
		segmentTree[ss + i] = a[i];
	}

	// Precalcular el resto del arbol
	for (int i = ss - 1; i; i--) {
		// Recordar que i<<1 == 2*i y 1<<1|1 == 2*1+1
		// segmentTree[i] = segmentTree[2 * i] + segmentTree[2 * i + 1];
		segmentTree[i] = segmentTree[i << 1] + segmentTree[i << 1 | 1];
	}
}

// Metodo para propagar de manera lazy en un arbol
void propagate(int n, int d) {
	if (lazy[n]) {
		segmentTree[n] += lazy[n] * d;
		if (n<ss) {
			lazy[n << 1] += lazy[n];
			lazy[n << 1 | 1] += lazy[n];
		}
		lazy[n] = 0;
	}
}

int query(int n, int l, int r, int d) { // [l,r]
										// solo ocupamos el metodo propagate si hay queries tipo 3
	propagate(n, d);
	// Opcion 2 el rango no es contenido
	if (l > r) return 0;
	// Opcion 1 porque l vale 0 y r vale d-1
	// el rango es: [0,d)
	if (!l && r == d - 1) {
		return segmentTree[n];
	}
	// Opcion 3: Notar que si el rango no contiene al hijo izquierdo l sera mayor a r y si no contiene al hijo derecho r sera menor a l
	d /= 2;
	return query(n << 1, l, min(d - 1, r), d) +
		query(2 * n + 1, max(0, l - d), r - d, d);
}

void query3(int n, int l, int r, int d, int x) {
	propagate(n, d);
	// Opcion 2 el rango no es contenido
	if (l > r) return;
	// Opcion 1 porque l vale 0 y r vale d-1
	// [0,d)
	if (!l && r == d - 1) {
		lazy[n] += x;
		propagate(n, d);
		return;
	}
	// Opcion 3
	d /= 2;
	query3(n << 1, l, min(d - 1, r), d, x);
	query3(2 * n + 1, max(0, l - d), r - d, d, x);
	// Reestablecemos los valores de este nodo porque cambiamos el valor de al menos a 1 de sus hijos 
	segmentTree[n] = segmentTree[n << 1] + segmentTree[n << 1 | 1];
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intQ, intS;
	scanf("%lld %lld %lld", &intN, &intQ, &intS);
	ss = 1 << (int)ceil(log2(intS));
	precalcSegmentTree(intS);
	FOR(intI, 0, intN)
	{
		ll intL, intR;
		scanf("%lld %lld", &intL, &intR);
		query3(1, intL, intR, ss, 1);
	}

	FOR(intI, 0, intQ)
	{
		ll intNext;
		scanf("%lld", &intNext);
		printf("%lld\n", query(1, intNext, intNext, ss));
	}

	return 0;
}
//======================================================================================================================