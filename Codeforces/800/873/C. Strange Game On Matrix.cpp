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
ll mat[105][105];
//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intM, intK;
	cin >> intN >> intM >> intK;
	memset(mat, 0, sizeof(mat));

	FOR(intI, 0, intN)
	{
		FOR(intJ, 0, intM)
		{
			cin >> mat[intI][intJ];
		}
	}

	FOR(intI, 1, intN)
	{
		FOR(intJ, 0, intM)
		{
			mat[intI][intJ] += mat[intI - 1][intJ];
		}
	}

	ll intChamp = 0, intRemoves = 0, intSum = 0, intCurRemoves;
	FOR(intJ, 0, intM)
	{
		intChamp = 0;
		intCurRemoves = 0;
		FOR(intI, intK - 1, intN)
		{
			if (mat[intI][intJ] - (intI ? mat[intI - intK][intJ] : 0) > intChamp)
			{
				intChamp = mat[intI][intJ] - (intI ? mat[intI - intK][intJ] : 0);
				intCurRemoves = (intI ? mat[intI - intK][intJ] : 0);
			}
		}

		intSum += intChamp;
		intRemoves += intCurRemoves;
	}

	cout << intSum << " " << intRemoves << endl;

	return 0;
}

//======================================================================================================================