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

vector<vi> AdjList(10005);
//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intT, intV, intE, intN, intV1, intV2, intSource;

	scanf("%lld", &intT);

	while (intT--)
	{
		for (ll intI = 0; intI < 1005; intI++)
		{
			AdjList[intI].clear();
		}

		scanf("%lld %lld", &intV, &intE);

		for (ll intI = 0; intI < intE; intI++)
		{
			scanf("%lld %lld", &intV1, &intV2);

			AdjList[intV1].push_back(intV2);
			AdjList[intV2].push_back(intV1);
		}
		
		scanf("%lld", &intSource);

		vi dist(intV + 1, 5000000000);
		dist[intSource] = 0;
		queue<int> q;
		q.push(intSource);

		while (!q.empty())
		{
			ll u = q.front();
			q.pop();

			for (ll intJ = 0; intJ < AdjList[u].size(); intJ++)
			{
				ll v = AdjList[u][intJ];

				if (dist[v] == 5000000000)
				{
					dist[v] = dist[u] + 6;
					q.push(v);
				}
			}
		}

		for (ll intI = 1; intI <= intV; intI++)
		{
			if (intI == intSource)
			{
				continue;
			}
			else if (dist[intI] == 5000000000)
			{
				printf("-1 ");
			}
			else
			{
				printf("%lld ", dist[intI]);
			}
		}

		printf("\n");
	}

	return 0;
}
//======================================================================================================================