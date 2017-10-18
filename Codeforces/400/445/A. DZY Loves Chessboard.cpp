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
	bool black = false;

	ll intN, intM;
	cin >> intN >> intM;
	string s;

	FOR(intI, 0, intN)
	{
		cin >> s;
		FOR(intJ, 0, intM)
		{
			if (s[intJ] == '-')
			{
				cout << "-";
			}
			else
			{
				if (black) cout << "B";
				else cout << "W";
			}

			black = !black;
		}

		if (intM % 2 == 0) black = !black;
		cout << endl;
	}

	return 0;
}

//======================================================================================================================