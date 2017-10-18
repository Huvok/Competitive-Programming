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
	string s;
	cin >> s;
	bool bad = false;

	FOR(intI, 0, s.length())
	{
		if (intI + 2 < s.length())
		{
			if (s[intI] == '1' &&
				s[intI + 1] == '4' &&
				s[intI + 2] == '4')
			{
				intI += 2;
				continue;
			}
		}
		
		if (intI + 1 < s.length())
		{
			if (s[intI] == '1' &&
				s[intI + 1] == '4')
			{
				intI += 1;
				continue;
			}
		}
		
		if (s[intI] == '1')
		{
			if (s[intI] == '1')
			{
				continue;
			}
		}

		cout << "NO" << endl;
		bad = true;
		break;
	}

	if (!bad)
	{
		cout << "YES" << endl;
	}

	return 0;
}
//======================================================================================================================