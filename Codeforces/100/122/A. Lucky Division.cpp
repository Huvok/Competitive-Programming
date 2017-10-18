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
bool isLucky(ll i)
{
	string s = to_string(i);

	FOR(intI, 0, s.length())
	{
		if (s[intI] != '4' &&
			s[intI] != '7')
		{
			return false;
		}
	}

	return true;
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN;
	cin >> intN;

	FOR(intI, 1, intN + 1)
	{
		if (isLucky(intI) && intN % intI == 0)
		{
			cout << "YES" << endl;
			break;
		}

		if (intI == intN)
		{
			cout << "NO" << endl;
		}
	}

	return 0;
}
//======================================================================================================================