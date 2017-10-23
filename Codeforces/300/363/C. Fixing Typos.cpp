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
#define RFOR(i, a, b) for(ll i=ll(a) - 1; i>=ll(b); i--)
#define pb push_back
#define mp make_pair
#define lld I64d
#define all(a) (a).begin(), (a).end()

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	string str;
	cin >> str;

	string ans = "";
	ll intCount = 0;
	FOR(intI, 0, str.length())
	{
		if (intI >= 2)
		{
			if (str[intI] == ans[intCount - 1] &&
				str[intI] == ans[intCount - 2])
			{
				continue;
			}

			if (intI >= 3)
			{
				if (str[intI] == ans[intCount - 1] &&
					ans[intCount - 2] == ans[intCount - 3])
				{
					continue;
				}
			}

			ans += str[intI];
			intCount++;
		}
		else
		{
			ans += str[intI];
			intCount++;
		}
	}

	cout << ans << endl;

	return 0;
}

//======================================================================================================================