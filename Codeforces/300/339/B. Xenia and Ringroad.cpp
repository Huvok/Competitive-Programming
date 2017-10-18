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
	ll intN, intQ;
	cin >> intN >> intQ;

	ll intNext;
	ll intSum = 0;
	ll intCur = 1;
	FOR(intI, 0, intQ)
	{
		cin >> intNext;
		if (intNext >= intCur)
		{
			intSum += (intNext - intCur);
		}
		else
		{
			intSum += (intN - intCur + intNext);
		}

		intCur = intNext;
	}

	cout << intSum << endl;

	return 0;
}
//======================================================================================================================