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
#include <climits>
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
set<ll> s;

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intP, intN;
	cin >> intP >> intN;
	ll intNext;
	FOR(intI, 0, intN)
	{
		cin >> intNext;
		if (s.find(intNext % intP) == s.end())
		{
			s.insert(intNext % intP);
		}
		else
		{
			cout << intI + 1 << endl;
			return 0;
		}
	}

	cout << -1 << endl;
	return 0;
}
//======================================================================================================================