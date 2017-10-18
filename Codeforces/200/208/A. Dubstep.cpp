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

	string ans = "";
	FOR(intI, 0, s.length())
	{
		if (intI + 2 < s.length())
		{
			if (s.substr(intI, 3) == "WUB")
			{
				intI += 2;
				if (ans.length() > 0 && ans[ans.length() - 1] != ' ') ans += " ";
				continue;
			}
		}

		ans += s[intI];
	}

	cout << (ans[ans.length() - 1] == ' ' ? ans.substr(0, ans.length() - 1) : ans) << endl;

	return 0;
}
//======================================================================================================================