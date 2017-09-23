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
vector<vi> v(256, vi(0));

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	string str;
	cin >> str;
	FOR(intI, 0, str.length())
	{
		v[str[intI]].pb(intI);
	}

	ll intQ;
	cin >> intQ;
	while(intQ--)
	{
		cin >> str;
		ll intIndex = -1, intFirst = 0;
		FOR(intI, 0, str.length())
		{
			vector<ll>::iterator i = upper_bound(v[str[intI]].begin(), v[str[intI]].end(), intIndex);
			intIndex = i - v[str[intI]].begin();
			if (i == v[str[intI]].end())
			{
				cout << "Not matched" << endl;
				break;
			}

			intIndex = v[str[intI]][intIndex];
			if (intI == 0) intFirst = intIndex;
			
			if (intI == str.length() - 1)
			{
				cout << "Matched " << intFirst << " " << intIndex << endl;
			}
		}
	}

	return 0;
}
//======================================================================================================================