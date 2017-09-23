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
ll mat[1005][1005];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intV, intE, intD, intT, intQ, intS, intMagnitude;
	cin >> intT;

	FOR(t, 0, intT)
	{
		cin >> intV >> intE >> intQ;
		FOR(intI, 0, intV + 1)
		{
			FOR(intJ, 0, intV + 1)
			{
				mat[intI][intJ] = INT_MAX;
			}
		}

		FOR(intI, 0, intE)
		{
			cin >> intS >> intD >> intMagnitude;
			mat[intS][intD] = min(mat[intS][intD], intMagnitude);
			mat[intD][intS] = mat[intS][intD];
		}

		FOR(intK, 1, intV + 1)
		{
			FOR(intI, 1, intV + 1)
			{
				FOR(intJ, 1, intV + 1)
				{
					mat[intI][intJ] = min(mat[intI][intJ], max(mat[intI][intK], mat[intK][intJ]));
				}
			}
		}

		cout << "Case " << t + 1 << ":" << endl;
		FOR(intI, 0, intQ)
		{
			cin >> intS >> intD;
			if (mat[intS][intD] != INT_MAX)
			{
				cout << mat[intS][intD] << endl;
			}
			else
			{
				cout << "no path" << endl;
			}
		}
	}

	return 0;
}
//======================================================================================================================