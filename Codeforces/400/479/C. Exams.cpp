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
ii arr[100005];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN;
	ll intA, intB;
	cin >> intN;

	ll intChamp = 0;
	FOR(intI, 0, intN) cin >> arr[intI].first >> arr[intI].second;
	sort(arr, arr + intN);
	FOR(intI, 0, intN)
	{
		if (intChamp <= arr[intI].second)
		{
			intChamp = arr[intI].second;
		}
		else
		{
			intChamp = arr[intI].first;
		}
	}

	cout << intChamp << endl;

	return 0;
}

//======================================================================================================================