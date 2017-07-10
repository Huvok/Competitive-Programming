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
ll intCost;
ll intR;

void dfs(int u)
{
	dfs_num[u] = 1;
	for (int j = 0; j < (int)AdjList[u].size(); j++)
	{
		ll v = AdjList[u][j];
		if (dfs_num[v] == 0)
		{
			intCost += intR;
			dfs(v);
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intT;

	cin >> intT;
	while (intT--)
	{
		ll intV, intE, intL;
		cin >> intV >> intE >> intL >> intR;
		dfs_num.clear();

		for (ll intI = 0; intI < intV; intI++)
		{
			AdjList[intI].clear();
			dfs_num.push_back(0);
		}

		ll intS, intD;
		for (ll intI = 0; intI < intE; intI++)
		{
			cin >> intS >> intD;
			AdjList[intS - 1].push_back(intD - 1);
			AdjList[intD - 1].push_back(intS - 1);
		}

		if (intL <= intR)
		{
			cout << intL * intV << endl;
		}
		else
		{
			intCost = 0;
			for (ll intI = 0; intI < intV; intI++)
			{
				if (dfs_num[intI] == 0)
				{
					intCost += intL;
					dfs(intI);
				}
			}

			cout << intCost << endl;
		}
	}
	
	return 0;
}
//======================================================================================================================