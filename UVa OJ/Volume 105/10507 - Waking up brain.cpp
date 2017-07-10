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
typedef pair<int, int> ii;
typedef vector<ii> vii;

//======================================================================================================================

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN;
	ll intE;
	
	while (scanf("%lld\n%lld", &intN, &intE) == 2)
	{
		unordered_map<char, int> m;
		string str;
		cin >> str;
		m.insert(make_pair(str[0], 1));
		m.insert(make_pair(str[1], 1));
		m.insert(make_pair(str[2], 1));

		vector<char> AdjList[30];
		vi indexes;
		for (ll intI = 0; intI < intE; intI++)
		{
			cin >> str;
			if (AdjList[(int)str[0] - 65].empty())
			{
				indexes.push_back((int)str[0] - 65);
			}

			AdjList[(int)str[0] - 65].push_back(str[1]);

			if (AdjList[(int)str[1] - 65].empty())
			{
				indexes.push_back((int)str[1] - 65);
			}

			AdjList[(int)str[1] - 65].push_back(str[0]);
		}

		sort(indexes.begin(), indexes.end());

		ll intCount = 0;
		vector<char> vToUpdate;
		while (m.size() < intN)
		{
			vToUpdate.clear();
			for (ll intI = 0; intI < indexes.size(); intI++)
			{
				ll intAwake = 0;
				char toFind = (char)(indexes[intI] + 65);
				if (m.find(toFind) != m.end())
				{
					indexes.erase(indexes.begin() + intI);
					intI--;
				}
				else
				{
					for (ll intJ = 0; intJ < AdjList[indexes[intI]].size(); intJ++)
					{
						if (m.find(AdjList[indexes[intI]][intJ]) != m.end())
						{
							intAwake++;
						}
					}

					if (intAwake >= 3)
					{
						vToUpdate.push_back((char)(indexes[intI] + 65));
					}
				}
			}

			intCount++;
			if (vToUpdate.empty())
			{
				cout << "THIS BRAIN NEVER WAKES UP" << endl;
				break;
			}

			for (ll intI = 0; intI < vToUpdate.size(); intI++)
			{
				m.insert(make_pair(vToUpdate[intI], 1));
			}
		}

		if (m.size() == intN)
			cout << "WAKE UP IN, " << intCount << ", YEARS" << endl;
	}

	return 0;
}
//======================================================================================================================