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

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intF = 0, intZ = 0;
	ll intN;
	cin >> intN;
	ll intNext;

	FOR(intI, 0, intN)
	{
		cin >> intNext;
		if (intNext == 5) intF++;
		else intZ++;
	}

	if (intZ == 0) cout << -1 << endl;
	else if (intF < 9) cout << 0 << endl;
	else
	{
		ll intMax = intF / 9;

		FOR(intI, 0, intMax * 9)
		{
			cout << 5;
		}

		FOR(intI, 0, intZ)
		{
			cout << 0;
		}

		cout << endl;
	}

	return 0;
}
//======================================================================================================================