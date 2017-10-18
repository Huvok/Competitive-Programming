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
ll dp[100005];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN;
	string s;
	cin >> intN >> s;
	memset(dp, 0, sizeof(dp));
	FOR(intI, 1, intN + 1)
	{
		if (s[intI - 1] == '1') dp[intI] = dp[intI - 1] - 1;
		else dp[intI] = dp[intI - 1] + 1;
	}

	unordered_map<ll, ll> m;
	ll intChamp = 0;
	FOR(intI, 0, intN + 1)
	{
		if (m.find(dp[intI]) == m.end())
		{
			m.insert(mp(dp[intI], intI));
		}
		else
		{
			intChamp = max(intChamp, intI - m[dp[intI]]);
		}
	}

	cout << intChamp << endl;

	return 0;
}

//======================================================================================================================