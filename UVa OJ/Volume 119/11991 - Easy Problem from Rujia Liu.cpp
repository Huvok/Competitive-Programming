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
vi AdjList[1000005];
//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intQ;

	while (scanf("%lld %lld", &intN, &intQ) == 2)
	{
		ll intNext;
		for (ll intI = 0; intI < intN; intI++)
		{
			AdjList[intI].clear();
		}

		for (ll intI = 0; intI < intN; intI++)
		{
			cin >> intNext;
			AdjList[intNext].push_back(intI + 1);
		}

		ll intNum, intOc;
		for (ll intI = 0; intI < intQ; intI++)
		{
			cin >> intOc >> intNum;
			if (AdjList[intNum].size() < intOc)
			{
				cout << 0 << endl; 
				continue;
			}
			cout << AdjList[intNum][intOc - 1] << endl;
		}
	}
	
	return 0;
}
//======================================================================================================================