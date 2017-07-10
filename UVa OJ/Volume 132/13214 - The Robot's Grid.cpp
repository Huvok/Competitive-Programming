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

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

//======================================================================================================================
ll dp[26][26];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	memset(dp, 0, sizeof dp);

	for (ll intI = 0; intI < 26; intI++)
	{
		for (ll intJ = 0; intJ < 26; intJ++)
		{
			if (!intJ ||
				!intI)
			{
				dp[intI][intJ] = 1;
			}
			else
			{
				for (ll intK = 0; intK <= intI; intK++)
				{
					dp[intI][intJ] += dp[intK][intJ - 1];
				}
			}
		}
	}

	ll intT, intI, intJ;
	cin >> intT;

	while (intT--)
	{
		cin >> intI >> intJ;
		cout << dp[intI - 1][intJ - 1] << endl;
	}
	
	return 0;
}
//======================================================================================================================