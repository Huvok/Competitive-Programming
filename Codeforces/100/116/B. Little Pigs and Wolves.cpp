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
string mat[15];
//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll intN, intM;
	cin >> intN >> intM;

	FOR(intI, 0, intN)
	{
		cin >> mat[intI];
	}

	ll intCount = 0;
	FOR(intI, 0, intN)
	{
		FOR(intJ, 0, intM)
		{
			if (mat[intI][intJ] == 'W')
			{
				if (intI && mat[intI - 1][intJ] == 'P')
				{
					intCount++;
				}
				else if (intJ && mat[intI][intJ - 1] == 'P')
				{
					intCount++;
				}
				else if (intI < intN - 1 && mat[intI + 1][intJ] == 'P')
				{
					intCount++;
				}
				else if (intJ < intM - 1 && mat[intI][intJ + 1] == 'P')
				{
					intCount++;
				}
			}
		}
	}

	cout << intCount << endl;

	return 0;
}

//======================================================================================================================