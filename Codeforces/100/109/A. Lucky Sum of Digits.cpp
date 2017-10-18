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
ll intFours = 0, intSevens = 0;
//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN;
	cin >> intN;
	ll intCur = intN;
	while (intCur >= 0)
	{
		intSevens++;
		intCur -= 7;
	}

	while (intCur <= intN)
	{
		if (intCur < 0)
		{
			while (intCur < 0)
			{
				intSevens--;
				intCur += 7;
			}
		}
		else if (intCur % 4 == 0)
		{
			intFours += intCur / 4;
			break;
		}
		else
		{
			intFours = 0;
			intSevens--;
			intCur += 7;
		}
	}

	if (intFours <= 0 &&
		intSevens <= 0)
	{
		cout << -1 << endl;
	}
	else
	{
		while (intFours > 0)
		{
			intFours--;
			cout << 4;
		}

		while (intSevens > 0)
		{
			intSevens--;
			cout << 7;
		}
	}

	cout << endl;
	return 0;
}
//======================================================================================================================