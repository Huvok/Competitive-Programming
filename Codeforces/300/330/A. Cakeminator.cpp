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
char arr[15][15];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intM;
	cin >> intN >> intM;

	FOR(intI, 0, intN)
	{
		cin >> arr[intI];
	}

	ll intAns = 0;
	ll intCols = 0;
	FOR(intJ, 0, intM)
	{
		FOR(intI, 0, intN)
		{
			if (arr[intI][intJ] == 'S') break;

			if (intI == intN - 1)
			{
				intAns += intN;
				intCols++;
			}
		}
	}

	FOR(intI, 0, intN)
	{
		FOR(intJ, 0, intM)
		{
			if (arr[intI][intJ] == 'S') break;

			if (intJ == intM - 1)
			{
				intAns += (intM - intCols);
			}
		}
	}

	cout << intAns << endl;

	return 0;
}
//======================================================================================================================