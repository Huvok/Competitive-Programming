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
	ll intCount = 0;
	string s;
	cin >> s;
	ll intSum;
	while (true)
	{
		if (s.length() <= 1) break;
		intCount++;
		intSum = 0;
		FOR(intI, 0, s.length())
		{
			intSum += (s[intI] - '0');
		}

		s = to_string(intSum);
	}

	cout << intCount << endl;

	return 0;
}
//======================================================================================================================