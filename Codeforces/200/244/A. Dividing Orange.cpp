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
vi kids[35];
//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll intN, intK;
	cin >> intN >> intK;
	unordered_set<ll> taken;

	ll intX;
	FOR(intI, 0, intK)
	{
		cin >> intX;
		kids[intI].pb(intX);
		taken.insert(intX);
	}

	ll intIndex = 0;
	ll intLeft = intN - 1;
	FOR(intI, 1, intN * intK + 1)
	{
		if (taken.find(intI) == taken.end())
		{
			kids[intIndex].pb(intI);
			intLeft--;
			if (intLeft == 0)
			{
				intIndex++;
				intLeft = intN - 1;
			}
		}
	}

	FOR(intI, 0, intK)
	{
		FOR(intJ, 0, intN)
		{
			cout << kids[intI][intJ] << " ";
		}

		cout << endl;
	}

	return 0;
}

//======================================================================================================================