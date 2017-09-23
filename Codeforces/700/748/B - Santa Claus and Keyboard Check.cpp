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
	string str1, str2;
	cin >> str1 >> str2;

	unordered_map<char, char> m1;
	vector<pair<char, char>> v;

	bool death = false;
	FOR(intI, 0, str1.length())
	{
		if (m1.find(str1[intI]) != m1.end() &&
			m1.find(str2[intI]) != m1.end())
		{
			if (m1[str1[intI]] != str2[intI] ||
				m1[str2[intI]] != str1[intI])
			{
				death = true;
				break;
			}
		}
		else if (m1.find(str1[intI]) != m1.end() ||
			m1.find(str2[intI]) != m1.end())
		{
			death = true;
			break;
		}
		else
		{
			m1.insert(mp(str1[intI], str2[intI]));
			m1.insert(mp(str2[intI], str1[intI]));
			if (str1[intI] != str2[intI]) v.pb(mp(str1[intI], str2[intI]));
		}
	}

	if (death) cout << -1 << endl;
	else
	{
		cout << v.size() << endl;
		FOR(intI, 0, v.size())
		{
			cout << v[intI].first << " " << v[intI].second << endl;
		}
	}

	return 0;
}
//======================================================================================================================