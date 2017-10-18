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

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intK;
	string s;
	cin >> intK;
	cin >> s;

	vector<string> v;
	bool arr[26];
	memset(arr, false, sizeof(arr));
	ll intLast = -1;
	ll k = intK;
	FOR(intI, 0, s.length())
	{
		if (!arr[s[intI] - 'a'])
		{
			arr[s[intI] - 'a'] = true;
			if (intLast == -1) intLast = 0;
			else
			{
				intK--;
				if (intK) v.pb(s.substr(intLast, intI - intLast));
				else v.pb(s.substr(intLast));
				intLast = intI;
			}
		}

		if (intK <= 0) break;
		if (intI == s.length() - 1) v.pb(s.substr(intLast));
	}

	if (v.size() < k)
	{
		cout << "NO" << endl;
	}
	else
	{
		cout << "YES" << endl;
		FOR(intI, 0, v.size())
		{
			cout << v[intI] << endl;
		}
	}
	return 0;
}
//======================================================================================================================