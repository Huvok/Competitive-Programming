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
ll fibo[55];
ll ans[55];
ll intN;

void solve(ll intI, ll intK)
{
	if (intI >= intN) return;

	if (fibo[intN - intI] < intK)
	{
		ans[intI] = intI + 2;
		ans[intI + 1] = intI + 1;
		intK -= fibo[intN - intI];
		solve(intI + 2, intK);
	}
	else
	{
		ans[intI] = intI + 1;
		solve(intI + 1, intK);
	}
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intK;
	cin >> intN >> intK;

	fibo[0] = 0;
	fibo[1] = 1;
	FOR(intI, 2, intN + 1)
	{
		fibo[intI] = fibo[intI - 1] + fibo[intI - 2];
	}

	solve(0, intK);

	FOR(intI, 0, intN)
	{
		cout << ans[intI] << " ";
	}

	cout << endl;

	return 0;
}
//======================================================================================================================