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

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN;
	cin >> intN;
	string s = to_string(intN);
	if (intN < 0)
	{
		if (intN > -10) cout << 0 << endl;
		else
		{
			ll a = atoi(s.substr(0, s.length() - 1).c_str());
			ll b = atoi((s.substr(0, s.length() - 2) + s[s.length() - 1]).c_str());
			cout << max(a, b) << endl;
		}
	}
	else cout << intN << endl;

	return 0;
}
//======================================================================================================================