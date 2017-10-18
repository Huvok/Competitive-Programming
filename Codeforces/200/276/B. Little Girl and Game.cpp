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
	ll intCount = 0;
	ll arr[26];
	memset(arr, 0, sizeof(arr));

	FOR(intI, 0, s.length())
	{
		arr[s[intI] - 'a']++;
	}

	FOR(intI, 0, 26)
	{
		if (arr[intI] % 2 != 0) intCount++;
	}

	if (intCount % 2 == 1 || intCount == 0) cout << "First" << endl;
	else cout << "Second" << endl;

	return 0;
}

//======================================================================================================================