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
	string a, b;
	cin >> a >> b;

	bool zero = false;
	bool can = true;
	FOR(intI, 0, a.length())
	{
		if (a[intI] == '1') zero = true;
	}

	if (!zero) can = false;
	zero = false;
	FOR(intI, 0, b.length())
	{
		if (b[intI] == '1') zero = true;
	}

	if (!zero) can = false;

	if (a.length() != b.length()) can = false;

	if (a == b) can = true;
	cout << (!can ? "NO" : "YES") << endl;

	return 0;
}

//======================================================================================================================