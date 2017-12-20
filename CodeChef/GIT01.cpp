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
char mat[105][105];

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll intT, intN, intM;
	cin >> intT;
	while (intT--)
	{
		cin >> intN >> intM;
		ll g = 0, r = 0;
		char cur = 'R';
		FOR(intI, 0, intN)
		{
			FOR(intJ, 0, intM)
			{
				cin >> mat[intI][intJ];
			}
		}

		FOR(intI, 0, intN)
		{
			if (intI & 1) cur = 'G';
			else cur = 'R';
			FOR(intJ, 0, intM)
			{
				if (cur != mat[intI][intJ])
				{
					if (cur == 'R') g++;
					else r++;
				}

				if (cur == 'R') cur = 'G';
				else cur = 'R';
			}
		}

		r *= 5;
		g *= 3;
		ll champ = g + r;

		cur = 'G';
		r = g = 0;
		FOR(intI, 0, intN)
		{
			if (intI & 1) cur = 'R';
			else cur = 'G';
			FOR(intJ, 0, intM)
			{
				if (cur != mat[intI][intJ])
				{
					if (cur == 'R') g++;
					else r++;
				}

				if (cur == 'R') cur = 'G';
				else cur = 'R';
			}
		}

		r *= 5;
		g *= 3;
		champ = min(champ, g + r);
		cout << champ << endl;
	}

	return 0;
}

//======================================================================================================================