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
	ll intN;
	cin >> intN;
	string str;
	cin >> str;

	ll intOnes = 0, intZeros = 0;

	FOR(intI, 0, intN)
	{
		if (str[intI] - '0')
		{
			intOnes++;
		}
		else
		{
			intZeros++;
		}
	}

	cout << abs(intOnes - intZeros) << endl;

	return 0;
}
//======================================================================================================================