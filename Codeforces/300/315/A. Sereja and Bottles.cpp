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
ll a[105], b[105];
//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN;
	cin >> intN;
	ll intNext;
	unordered_map<ll, ll> m;
	FOR(intI, 0, intN)
	{
		cin >> a[intI];
		cin >> b[intI];
	}

	ll intCount = intN;
	FOR(intI, 0, intN)
	{
		FOR(intJ, 0, intN)
		{
			if (intI != intJ &&
				a[intI] == b[intJ])
			{
				intCount--;
				break;
			}
		}
	}

	cout << intCount << endl;

	return 0;
}

//======================================================================================================================