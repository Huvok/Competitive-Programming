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
	string s;
	ll intN;
	cin >> s;
	cin >> intN;

	if (intN == 1)
	{
		FOR(intI, 0, s.length())
		{
			if (s[intI] != s[s.length() - intI - 1])
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	else if (s.length() % intN != 0)
	{
		cout << "NO" << endl;
		return 0;
	}
	else
	{
		vector<string> v;
		ll intCur = 0;
		while (intCur < s.length())
		{
			v.pb(s.substr(intCur, s.length() / intN));
			intCur += (s.length() / intN);
		}

		FOR(intJ, 0, v.size())
		{
			FOR(intI, 0, v[intJ].length())
			{
				if (v[intJ][intI] != v[intJ][v[intJ].length() - intI - 1])
				{
					cout << "NO" << endl;
					return 0;
				}
			}
		}
	}
	cout << "YES" << endl;
	return 0;
}
//======================================================================================================================