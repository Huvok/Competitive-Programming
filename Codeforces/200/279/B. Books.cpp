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
#define RFOR(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define pb push_back
#define mp make_pair
#define lld I64d
#define all(a) (a).begin(), (a).end()

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
ll arr[100005];

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll intN, intT;
	cin >> intN >> intT;

	FOR(intI, 0, intN) cin >> arr[intI];

	ll intL = 0, intR = 0;
	ll intChamp = 0;
	while (intR < intN)
	{
		if (intT >= arr[intR])
		{
			intT -= arr[intR];
			intR++;
		}
		else if (intL >= intR)
		{
			intR++;
			intL = intR;
		}
		else
		{
			intT += arr[intL];
			intL++;
		}
		intChamp = max(intChamp, intR - intL);
	}

	cout << intChamp << endl;

	return 0;
}

//======================================================================================================================