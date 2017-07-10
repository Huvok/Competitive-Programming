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
vi AdjList[100005];
ll cc = 1;

ll dp[100005][2][2];
ll done[100005][2][2];

ll f(ll intParent, ll intP, ll intCurrent, ll intAlly);

ll g(ll intParent, ll intP, ll intC, ll intCurrent, ll intAlly) 
{
	ll intResult = 0;

	if (intC == AdjList[intParent].size()) 
	{
		return intAlly;
	}

	ll intTest = AdjList[intParent][intC];

	if (intTest == intP)
	{
		intResult = g(intParent, intP, intC + 1, intCurrent, intAlly);
		return intResult;
	}

	if (done[intTest][intCurrent][intAlly] == cc) return dp[intTest][intCurrent][intAlly];
	done[intTest][intCurrent][intAlly] = cc;

	intResult = f(intTest, intParent, intCurrent, 1) * g(intParent, intP, intC + 1, intCurrent, 1);
	intResult %= 1000000007;

	ll temp = f(intTest, intParent, 1 - intCurrent, 0) * g(intParent, intP, intC + 1, intCurrent, intAlly);
	temp %= 1000000007;

	intResult += temp;

	if (intResult >= 1000000007)
	{
		intResult -= 1000000007;
	}

	return dp[intTest][intCurrent][intAlly] = intResult;
}

ll f(ll intParent, ll intP, ll intCurrent, ll intAlly)
{
	ll intResult = g(intParent, intP, 0, intCurrent, intAlly);
	return intResult;
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN;
	cin >> intN;

	for (ll intI = 1; intI <= intN; intI++)
	{
		AdjList[intI].clear();
	}

	ll intS, intD;
	for (ll intI = 0; intI < intN - 1; intI++)
	{
		cin >> intS >> intD;
		AdjList[intS].push_back(intD);
		AdjList[intD].push_back(intS);
	}

	cc++;
	ll intResult = f(1, 0, 0, 0);
	intResult += f(1, 0, 1, 0);
	
	if (intResult >= 1000000007)
	{
		intResult -= 1000000007;
	}

	cout << intResult << endl;

	return 0;
}
//======================================================================================================================