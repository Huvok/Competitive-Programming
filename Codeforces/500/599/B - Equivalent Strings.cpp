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
string strA, strB;
map<string, bool> m;
bool solve(string a, string b)
{
	if (m.find(a + b) != m.end()) return m[a + b];
	if (a == b)
	{
		return true;
	}
	else if (a.length() % 2 != 0) return false;
	else
	{
		bool res = ((solve(a.substr(0, a.length() / 2), b.substr(0, b.length() / 2)) &&
			solve(b.substr(b.length() / 2), a.substr(a.length() / 2))) ||
			((solve(a.substr(0, a.length() / 2), b.substr(b.length() / 2)) &&
				solve(a.substr(a.length() / 2), b.substr(0, b.length() / 2)))));

		m.insert(mp(a + b, res));
		return res;
	}
}
//----------------------------------------------------------------------------------------------------------------------
int main()
{
	cin >> strA;
	cin >> strB;

	if (solve(strA, strB))
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}

	return 0;
}
//======================================================================================================================