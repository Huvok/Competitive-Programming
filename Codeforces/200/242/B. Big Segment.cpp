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
ii arr[100005];

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll intN;
	cin >> intN;

	ll intMin = INT_MAX;
	ll intMax = INT_MIN;

	ll a, b;
	FOR(intI, 0, intN)
	{
		cin >> a >> b;
		arr[intI] = mp(a, b);
		intMin = min(intMin, a);
		intMax = max(intMax, b);
	}

	ll ans = -1;
	FOR(intI, 0, intN)
	{
		if (arr[intI].first <= intMin &&
			arr[intI].second >= intMax)
		{
			ans = intI + 1;
			break;
		}
	}

	cout << ans << endl;

	return 0;
}

//======================================================================================================================