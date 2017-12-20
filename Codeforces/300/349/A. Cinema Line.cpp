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

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll n, c25 = 0, c50 = 0;
	cin >> n;
	FOR(i, 0, n)
	{
		ll x;
		cin >> x;
		if (x == 50)
		{
			if (c25)
			{
				c25--;
				c50++;
			}
			else
			{
				cout << "NO" << endl;
				break;
			}
		}
		else if (x == 100)
		{
			if (c50 && c25)
			{
				c50--; c25--;
			}
			else if (c25 >= 3)
			{
				c25 -= 3;
			}
			else
			{
				cout << "NO" << endl;
				break;
			}
		}
		else
			c25++;

		if (i == n - 1)
		{
			cout << "YES" << endl;
		}
	}

	return 0;
}

//====================================================================================================================== 