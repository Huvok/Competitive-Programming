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

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intK, intM, intSize;
	cin >> intN >> intK;

	ll intRet = 2 * intN - intK + 1;
	FOR(intI, 0, intK)
	{
		cin >> intM;
		FOR(intJ, 0, intM)
		{
			cin >> intSize;
			if (intSize == intJ + 1)
			{
				intRet -= 2;
			}
		}
	}

	cout << intRet << endl;

	return 0;
}
//======================================================================================================================