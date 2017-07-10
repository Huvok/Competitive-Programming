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
vi dfs_num;
ll intComponentSize;

void dfs(ll u)
{
	intComponentSize++;
	dfs_num[u] = 1;
	for (ll intJ = 0; intJ < (ll)AdjList[u].size(); intJ++)
	{
		ll v = AdjList[u][intJ];
		if (dfs_num[v] == 0)
		{
			dfs(v);
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intV, intE;

	cin >> intV >> intE;

	ll intS, intD;
	dfs_num.assign(intV, 0);

	for (ll intI = 0; intI < intE; intI++)
	{
		cin >> intS >> intD;
		AdjList[intS].push_back(intD);
		AdjList[intD].push_back(intS);
	}

	ll intSum = intV * (intV - 1) / 2;
	for (ll intI = 0; intI < intV; intI++)
	{
		if (dfs_num[intI] == 0)
		{
			intComponentSize = 0;
			dfs(intI);
			intSum -= (intComponentSize * (intComponentSize - 1) / 2);
		}
	}

	cout << intSum << endl;
	
	return 0;
}
//======================================================================================================================