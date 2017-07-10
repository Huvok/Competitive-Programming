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
ll dp[100005], arr[100005], arrSum[100005];

//----------------------------------------------------------------------------------------------------------------------
using namespace std;

int main()
{
	ll intT, intN;

	scanf("%lld", &intT);

	while (intT--)
	{
		scanf("%lld", &intN);
		for (ll intI = intN - 1; intI >= 0; intI--)
		{
			scanf("%lld", &arr[intI]);
		}

		arrSum[0] = arr[0];
		arrSum[1] = arr[1] + arrSum[0];
		arrSum[2] = arr[2] + arrSum[1];
		dp[0] = arrSum[0];
		dp[1] = arrSum[1];
		dp[2] = arrSum[2];
		for (ll intI = 3; intI < intN; intI++)
		{
			arrSum[intI] = arrSum[intI - 1] + arr[intI];
			dp[intI] = max(max(arrSum[intI - 1] - dp[intI - 1] + arr[intI],
				arrSum[intI - 2] - dp[intI - 2] + arr[intI] + arr[intI - 1]), 
				arrSum[intI - 3] - dp[intI - 3] + arr[intI] + arr[intI - 1] + arr[intI - 2]);
		}

		printf("%lld\n", dp[intN - 1]);
	}
	return 0;
}
//======================================================================================================================