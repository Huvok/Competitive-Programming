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
#include <climits>
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
vii v;

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intX;
	cin >> intN >> intX;

	FOR(intI, 0, intN)
	{
		ll l, r;
		cin >> l >> r;
		v.pb(mp(l, r));
	}

	sort(v.begin(), v.end());

	ll intCount = 0;
	ll intCur = 1;

	ll i = 0;
	while (true)
	{
		if (intCur + intX <= v[i].first) intCur += intX;
		else
		{
			intCount += (v[i].first - intCur);
			intCount += (v[i].second - v[i].first + 1);
			intCur = v[i].second + 1;
			i++;
		}

		if (i >= v.size()) break;
	}
	cout << intCount << endl;
	return 0;
}
//======================================================================================================================