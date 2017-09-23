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
pair<ii, ll> arr[200005];
set<ii> bridges;

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intM;

	cin >> intN >> intM;

	if (intM < intN - 1)
	{
		cout << "No" << endl;
		return 0;
	}

	ll intL, intR, intNewL, intNewR;
	cin >> intL >> intR;
	FOR(intI, 1, intN)
	{
		cin >> intNewL >> intNewR;
		arr[intI - 1].first.first = intNewR - intL;
		arr[intI - 1].first.second = intNewL - intR;
		arr[intI - 1].second = intI;
		intL = intNewL;
		intR = intNewR;
	}

	ll intLength;
	FOR(intI, 0, intM)
	{
		cin >> intLength;
		bridges.insert(mp(intLength, intI + 1));
	}

	sort(arr, arr + intN - 1);
	vi ans(intN);
	FOR(intI, 0, intN - 1)
	{
		ll intBig = arr[intI].first.first, intSmall = arr[intI].first.second, intNum = arr[intI].second;
		auto it = bridges.lower_bound(mp(intSmall, -1));
		if (it == bridges.end() ||
			it->first > intBig)
		{
			cout << "No" << endl;
			return 0;
		}
		ans[intNum] = it->second;
		bridges.erase(it);
	}

	cout << "Yes" << endl;
	FOR(intI, 1, intN)
	{
		cout << ans[intI] << " ";
	}

	return 0;
}
//======================================================================================================================