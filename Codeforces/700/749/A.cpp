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
int main()
{
	ll intN;
	cin >> intN;

	ll intSum = 0;
	ll intTwos = 0;
	ll intThrees = 0;
	while (intN)
	{
		if (intN > 1)
		{
			intN -= 2;
			intTwos++;
			intSum++;
		}
		else
		{
			if (intN == 1)
			{
				intTwos--;
				intThrees++;
				intN--;
			}
		}
	}

	cout << intSum << endl;
	FOR(intI, 0, intTwos)
	{
		cout << "2";
		if (intI != intTwos - 1) cout << " ";
	}

	if (intThrees) cout << " 3" << endl;
	else cout << endl;

	return 0;
}
//======================================================================================================================