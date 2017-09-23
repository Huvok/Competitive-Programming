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

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
ll dp[11][101][101];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intQ, intC;
	memset(dp, 0, sizeof(dp));
	cin >> intN >> intQ >> intC;
	ll intX, intY, intS;

	for (ll intI = 0; intI < intN; intI++)
	{
		cin >> intX >> intY >> intS;
		dp[intS][intX][intY]++;
	}

	for (ll intI = 0; intI <= intC; intI++)
	{
		for (ll intJ = 1; intJ < 101; intJ++)
		{
			for (ll intK = 1; intK < 101; intK++)
			{
				dp[intI][intJ][intK] += dp[intI][intJ - 1][intK] + dp[intI][intJ][intK - 1] - dp[intI][intJ - 1][intK - 1];
			}
		}
	}

	ll intT, intX1, intX2, intY1, intY2;

	for (ll intI = 0; intI < intQ; intI++)
	{
		ll intRes = 0;
		cin >> intT >> intX1 >> intY1 >> intX2 >> intY2;

		for (ll intJ = 0; intJ <= intC; intJ++)
		{
			intRes += (intJ + intT) % (intC + 1) * (dp[intJ][intX2][intY2] - dp[intJ][intX1 - 1][intY2] - 
				dp[intJ][intX2][intY1 - 1] + dp[intJ][intX1 - 1][intY1 - 1]);
		}

		cout << intRes << endl;
	}

	return 0;
}
//======================================================================================================================