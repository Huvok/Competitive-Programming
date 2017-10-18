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

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	string s1, s2;
	cin >> s1 >> s2;

	if (s1.length() != s2.length())
	{
		cout << "NO" << endl;
	}
	else
	{
		FOR(intI, 0, s1.length())
		{
			if (s1[intI] != s2[s2.length() - 1 - intI])
			{
				cout << "NO" << endl;
				break;
			}

			if (intI == s1.length() - 1)
			{
				cout << "YES" << endl;
			}
		}
	}

	return 0;
}
//======================================================================================================================