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

using namespace std;

//															//AUTHOR: Hugo Garcia
//															//PURPOSE: Competitive programming template

//======================================================================================================================

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define pb push_back
#define mp make_pair
#define lld I64d

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
ll arr[100005];
ll intK;
void solve(ll i, ll j)
{
	if (intK <= 0) return;
	if (i >= j) return;
	ll m = ((j - i) >> 1) + i;
	if ((j - i) % 2 == 1) swap(arr[m], arr[m + 1]);
	else swap(arr[m], arr[m - 1]);
	intK -= 2;
	if ((j - i) % 2 == 0)
	{
		solve(i, m - 1);
		solve(m, j);
	}
	else
	{
		solve(i, m);
		solve(m + 1, j);
	}
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN;
	cin >> intN >> intK;

	if (intK % 2 == 0)
	{
		cout << -1 << endl;
	}
	else
	{
		FOR(intI, 1, intN + 1)
		{
			arr[intI - 1] = intI;
		}

		intK--;
		solve(0, intN - 1);

		if (intK > 0) cout << -1 << endl;
		else
		{
			FOR(intI, 0, intN)
			{
				cout << arr[intI] << " ";
			}
		}

		cout << endl;
	}

	return 0;
}

//======================================================================================================================