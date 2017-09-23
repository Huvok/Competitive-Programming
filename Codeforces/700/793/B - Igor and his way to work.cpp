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
ll arr[1005][1005], intN, intM;
bool dp[1005][1005][4][10];

bool solve(ll intI, ll intJ, ll intDir, ll intTurns)
{
	if (intTurns > 2) return false;
	if (intI < 0 ||
		intI >= intN ||
		intJ < 0 ||
		intJ >= intM)
	{
		return false;
	}

	if (dp[intI][intJ][intDir][intTurns]) return false;
	dp[intI][intJ][intDir][intTurns] = true;
	if (arr[intI][intJ] == 2) return true;
	else if (arr[intI][intJ] == -1) return false;
	else
	{
		if (intDir == 1)
		{
			return (solve(intI - 1, intJ, 1, intTurns) ||
				solve(intI, intJ + 1, 2, intTurns + 1) ||
				solve(intI, intJ - 1, 4, intTurns + 1));
		}
		else if (intDir == 2)
		{
			return (solve(intI - 1, intJ, 1, intTurns + 1) ||
				solve(intI, intJ + 1, 2, intTurns) ||
				solve(intI + 1, intJ, 3, intTurns + 1));
		}
		else if (intDir == 3)
		{
			return (solve(intI, intJ + 1, 2, intTurns + 1) ||
				solve(intI + 1, intJ, 3, intTurns) ||
				solve(intI, intJ - 1, 4, intTurns + 1));
		}
		else
		{
			return (solve(intI - 1, intJ, 1, intTurns + 1) ||
				solve(intI + 1, intJ, 3, intTurns + 1) ||
				solve(intI, intJ - 1, 4, intTurns));
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	cin >> intN >> intM;
	memset(arr, 0, sizeof(arr));
	string str;
	ll intStartI, intStartJ;
	FOR(intI, 0, intN)
	{
		cin >> str;
		FOR(intJ, 0, intM)
		{
			if (str[intJ] == 'S')
			{
				arr[intI][intJ] = 1;
				intStartI = intI;
				intStartJ = intJ;
			}
			else if (str[intJ] == 'T') arr[intI][intJ] = 2;
			else if (str[intJ] == '*') arr[intI][intJ] = -1;
		}
	}

	if (solve(intStartI - 1, intStartJ, 1, 0) ||
		solve(intStartI, intStartJ + 1, 2, 0) ||
		solve(intStartI + 1, intStartJ, 3, 0) ||
		solve(intStartI, intStartJ - 1, 4, 0))
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}

	return 0;
}
//======================================================================================================================