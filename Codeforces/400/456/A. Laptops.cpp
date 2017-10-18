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
ii a[100005], b[100005];
//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN;
	cin >> intN;

	FOR(intI, 0, intN)
	{
		cin >> a[intI].first >> b[intI].first;
		a[intI].second = intI; b[intI].second = intI;
	}

	sort(a, a + intN);
	sort(b, b + intN);

	FOR(intI, 0, intN)
	{
		if (a[intI].second != b[intI].second)
		{
			cout << "Happy Alex" << endl;
			break;
		}

		if (intI == intN - 1)
		{
			cout << "Poor Alex" << endl;
		}
	}

	return 0;
}
//======================================================================================================================