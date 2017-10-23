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
ll arr[300005];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intK;
	cin >> intN >> intK;

	FOR(intI, 0, intN) cin >> arr[intI];

	FOR(intI, 1, intN) arr[intI] += arr[intI - 1];

	ll a = 0, b = intK, intCandidate = 0;
	FOR(intI, intK + 1, intN - intK + 1)
	{
		if (arr[intI - 1] - arr[intI - intK - 1] > arr[intCandidate + intK - 1] - (intCandidate ? arr[intCandidate - 1] : 0))
		{
			intCandidate = intI - intK;
		}

		if (arr[intI + intK - 1] - arr[intI - 1] + arr[intCandidate + intK - 1] - (intCandidate ? arr[intCandidate - 1] : 0) >
			arr[b + intK - 1] - arr[b - 1] + arr[a + intK - 1] - (a ? arr[a - 1] : 0))
		{
			a = intCandidate;
			b = intI;
		}
	}

	a++; b++;
	cout << a << " " << b << endl;

	return 0;
}

//======================================================================================================================