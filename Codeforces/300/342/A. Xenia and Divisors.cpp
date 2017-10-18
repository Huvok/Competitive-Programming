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
ll arr[8];

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll intN;
	cin >> intN;

	ll intNext;
	FOR(intI, 0, intN)
	{
		cin >> intNext;
		arr[intNext]++;
	}

	vector<string> ans;
	while (arr[1] > 0 && arr[2] > 0 && arr[4] > 0)
	{
		arr[1]--; arr[2]--; arr[4]--;
		ans.pb("1 2 4");
	}

	while (arr[1] > 0 && arr[2] > 0 && arr[6] > 0)
	{
		arr[1]--; arr[2]--; arr[6]--;
		ans.pb("1 2 6");
	}

	while (arr[1] > 0 && arr[3] > 0 && arr[6] > 0)
	{
		arr[1]--; arr[3]--; arr[6]--;
		ans.pb("1 3 6");
	}

	FOR(intI, 0, 8)
	{
		if (arr[intI] != 0)
		{
			cout << -1 << endl;
			return 0;
		}
	}

	FOR(intI, 0, ans.size())
	{
		cout << ans[intI] << endl;
	}

	return 0;
}

//======================================================================================================================