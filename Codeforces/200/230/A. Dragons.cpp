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
ii arr[1005];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intK;
	cin >> intK >> intN;

	FOR(intI, 0, intN)
	{
		cin >> arr[intI].first >> arr[intI].second;
	}

	sort(arr, arr + intN);

	FOR(intI, 0, intN)
	{
		if (arr[intI].first < intK)
		{
			intK += arr[intI].second;
		}
		else
		{
			cout << "NO" << endl;
			break;
		}

		if (intI == intN - 1) cout << "YES" << endl;
	}

	return 0;
}
//======================================================================================================================