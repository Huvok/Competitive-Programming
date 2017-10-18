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

	string a, b, c;
	cin >> a >> b >> c;

	FOR(intI, 0, a.length()) arr[a[intI] - 'A']++;
	FOR(intI, 0, b.length()) arr[b[intI] - 'A']++;
	FOR(intI, 0, c.length()) arr[c[intI] - 'A']--;
	
	FOR(intI, 0, 26)
	{
		if (arr[intI] != 0)
		{
			cout << "NO" << endl;
			break;
		}
		else if (intI == 25) cout << "YES" << endl;
	}

	return 0;
}
//======================================================================================================================