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
class Solution 
{
public:
	#define MOD 1000000007
	int dp[1001][1001];
	int kInversePairs(int n, int k)
	{
		memset(dp, -1, sizeof dp);
		return (intCountInv(n, k) - (k > 0 ? intCountInv(n, k - 1) : 0) + MOD) % MOD;
	}

	int intCountInv(int intN, int intK)
	{
		if (intN == 0) return 0;
		if (intK == 0) return 1;
		if (dp[intN][intK] != -1) return dp[intN][intK];
		int intPastValue = (intCountInv(intN - 1, intK) - 
			(intK - intN >= 0 ? intCountInv(intN - 1, intK - intN) : 0) + MOD) % MOD;
		return dp[intN][intK] = (intPastValue + intCountInv(intN, intK - 1)) % MOD;
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	Solution sol;
	cout << sol.kInversePairs(4, 5) << endl;

	return 0;
}
//======================================================================================================================