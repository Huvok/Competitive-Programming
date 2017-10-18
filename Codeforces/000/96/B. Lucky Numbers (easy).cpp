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
vi ans;
void populate(ll i, ll fours, ll sevens)
{
	if (i > 1e11) return;

	if (i && fours == sevens) ans.pb(i);

	populate(i * 10 + 4, fours + 1, sevens);
	populate(i * 10 + 7, fours, sevens + 1);
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	populate(0, 0, 0);
	ll intN;
	cin >> intN;

	sort(ans.begin(), ans.end());

	auto it = lower_bound(ans.begin(), ans.end(), intN) - ans.begin();
	cout << ans[it] << endl;

	return 0;
}

//======================================================================================================================