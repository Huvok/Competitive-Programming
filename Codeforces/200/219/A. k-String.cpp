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
	ll arr[26];
	memset(arr, 0, sizeof(arr));
	ll intN;
	cin >> intN;
	string s;
	cin >> s;

	FOR(intI, 0, s.length())
	{
		arr[s[intI] - 'a']++;
	}

	string ans = "";

	FOR(intI, 0, 26)
	{
		if (arr[intI] != 0 &&
			arr[intI] % intN == 0)
		{
			FOR(intJ, 0, arr[intI] / intN)
				ans += (intI + 'a');
		}
		else if (arr[intI] != 0 &&
			arr[intI] % intN != 0)
		{
			cout << -1 << endl;
			return 0;
		}
	}

	FOR(intI, 0, intN)
	{
		cout << ans;
	}

	cout << endl;

	return 0;
}
//======================================================================================================================