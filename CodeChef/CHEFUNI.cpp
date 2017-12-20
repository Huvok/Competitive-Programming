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
ll intT, a, b, c, x, y, z;

ll fullA()
{
	return (x + y + z) * a;
}

ll scalateB()
{
	ll ans = 0;

	if ((x && y) ||
		(x && z) ||
		(y && z))
	{
		ll intMin = min(x == 0 ? INT_MAX : x, min(y == 0 ? INT_MAX : y, z == 0 ? INT_MAX : z));
		ll intMax = max(x, max(y, z));

		ans += (intMin * b);
		if (x == intMin)
		{
			x -= intMin;

			if (intMax == y)
				y -= intMin;
			else
				z -= intMin;
		}
		else if (y == intMin)
		{
			y -= intMin;

			if (intMax == x)
				x -= intMin;
			else
				z -= intMin;
		}
		else
		{
			z -= intMin;

			if (intMax == x)
				x -= intMin;
			else
				y -= intMin;
		}

		return ans + scalateB();
	}

	return ans;
}

ll flatB()
{
	ll ans = 0;

	if (x && y && z)
	{
		ll intMin = min(x == 0 ? INT_MAX : x, min(y == 0 ? INT_MAX : y, z == 0 ? INT_MAX : z));
		if (intMin & 1) intMin--;
		ans += (intMin / 2) * b * 3;
		x -= intMin; y -= intMin; z -= intMin;
	}

	return ans;
}

ll fullC()
{
	ll ans = 0;

	if (x && y && z)
	{
		ll intMin = min(x == 0 ? INT_MAX : x, min(y == 0 ? INT_MAX : y, z == 0 ? INT_MAX : z));
		x -= intMin; y -= intMin; z -= intMin;
		ans += intMin * c;
	}

	return ans;
}

ll oneC()
{
	ll ans = 0;

	if (x && y && z)
	{
		ll intMin = 1;
		x -= intMin; y -= intMin; z -= intMin;
		ans += intMin * c;
	}

	return ans;
}

ll maxToMinB()
{
	ll ans = 0;

	if ((x && y) ||
		(x && z) ||
		(y && z))
	{
		ll intMin = min(x, min(y, z));
		ll intMax = max(x, max(y, z));
		ll intMid;

		if (x == intMin)
		{
			if (intMax == y)
				intMid = z;
			else
				intMid = y;
		}
		else if (y == intMin)
		{
			if (intMax == x)
				intMid = z;
			else
				intMid = x;
		}
		else
		{
			if (intMax == x)
				intMid = y;
			else
				intMid = x;
		}

		ll dead;
		if (intMid >= (intMax - intMin))
		{
			ans += (intMax - intMin) * b;
			dead = (intMax - intMin);
		}
		else
		{
			ans += intMin * b;
			dead = intMin;
		}

		if (x == intMid)
		{
			x -= dead;

			if (intMax == y)
				y -= dead;
			else
				z -= dead;
		}
		else if (y == intMid)
		{
			y -= dead;

			if (intMax == x)
				x -= dead;
			else
				z -= dead;
		}
		else
		{
			z -= dead;

			if (intMax == x)
				x -= dead;
			else
				y -= dead;
		}
	}

	return ans;
}

ll solve()
{
	ll intChamp = INT_MAX;
	ll oldx = x, oldy = y, oldz = z;

	ll c1 = fullA();
	ll c2 = scalateB();
	c2 += fullA();
	x = oldx, y = oldy, z = oldz;

	ll c3 = flatB();
	c3 += fullA();
	x = oldx, y = oldy, z = oldz;

	ll c4 = flatB();
	c4 += scalateB();
	c4 += fullA();
	x = oldx, y = oldy, z = oldz;

	ll c5 = fullC();
	c5 += scalateB();
	c5 += fullA();
	x = oldx, y = oldy, z = oldz;

	ll c6 = oneC();
	c6 += scalateB();
	c6 += fullA();
	x = oldx, y = oldy, z = oldz;

	ll c7 = fullC();
	c7 += flatB();
	ll c8 = c7;
	c7 += fullA();
	c8 += scalateB();
	c8 += fullA();
	x = oldx, y = oldy, z = oldz;

	ll c9 = fullC();
	c9 += scalateB();
	c9 += fullA();
	x = oldx, y = oldy, z = oldz;

	ll c10 = maxToMinB();
	c10 += flatB();
	c10 += scalateB();
	c10 += fullA();
	x = oldx, y = oldy, z = oldz;

	ll c11 = maxToMinB();
	c11 += maxToMinB();
	c11 += flatB();
	c11 += scalateB();
	c11 += fullA();
	x = oldx, y = oldy, z = oldz;

	ll c12 = maxToMinB();
	c12 += maxToMinB();
	c12 += fullC();
	c12 += scalateB();
	c12 += fullA();
	x = oldx, y = oldy, z = oldz;

	ll c13 = maxToMinB();
	c13 += maxToMinB();
	c13 += flatB();
	c13 += fullC();
	c13 += fullA();

	return min(c1, min(c2, min(c3, min(c4, min(c5, min(c6, min(c7, min(c8, min(c9, min(c10, min(c11, min(c12, c13))))))))))));
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	scanf("%lld", &intT);

	while (intT--)
	{
		scanf("%lld %lld %lld %lld %lld %lld", &x, &y, &z, &a, &b, &c);

		printf("%lld\n", solve());
	}

	return 0;
}

//======================================================================================================================  