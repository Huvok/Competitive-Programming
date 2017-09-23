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
#include <climits>
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
double hyp(double x, double y) 
{
	return sqrt(x * x + y * y);
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	double x1, y1, x2, y2, L;
	cout << setprecision(8) << fixed;

	while (!(cin >> x1 >> y1 >> x2 >> y2 >> L).eof())
	{
		if (abs(y1 - y2) < .00000000005)
		{
			double x = (x1 + x2) / 2;
			double dx = x1 - x2;
			double y = y1 - sqrt(L * L - dx * dx) / 2;
			cout << x << " " << y << endl;
		}
		else
		{
			double x = 0, y = 0;
			double inf = -1e8;
			double sup = min(y1, y2);
			FOR(intI, 0, 1000)
			{
				y = (inf + sup) / 2;
				double yNext = 2 * y - y2;
				x = x1 + (y - y1) * (x2 - x1) / (yNext - y1);
				double l2 = hyp(x - x1, y - y1) + hyp(x - x2, y - yNext);

				if (l2 <= L)
				{
					sup = y;
				}
				else
				{
					inf = y;
				}
			}

			cout << x << " " << y << endl;
		}
	}

	return 0;
}
//======================================================================================================================