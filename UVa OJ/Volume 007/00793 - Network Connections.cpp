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
class UnionFind
{
private:
	vi p, rank;

public:
	UnionFind(ll N)
	{
		rank.assign(N, 0);
		p.assign(N, 0);

		for (ll i = 0; i < N; ++i)
		{
			p[i] = i;
		}
	}

	ll findSet(ll i)
	{
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}

	bool isSameSet(ll i, ll j)
	{
		return findSet(i) == findSet(j);
	}

	void unionSet(ll i, ll j)
	{
		if (!isSameSet(i, j))
		{
			ll x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y])
			{
				p[y] = x;
			}
			else
			{
				p[x] = y;

				if (rank[x] == rank[y])
				{
					rank[y]++;
				}
			}
		}
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intT;
	cin >> intT;

	ll intN;
	cin >> intN;
	ll intGood = 0, intBad = 0;
	UnionFind uf(intN + 1);
	char str[1000000];
	ll intS, intD;
	while (true)
	{
		if (scanf("%s", &str) > 0)
		{
			if (str[0] == 'q')
			{
				cin >> intS >> intD;
				if (uf.isSameSet(intS, intD))
				{
					intGood++;
				}
				else
				{
					intBad++;
				}
			}
			else if (str[0] == 'c')
			{
				cin >> intS >> intD;
				uf.unionSet(intS, intD);
			}
			else
			{
				cout << intGood << "," << intBad << endl << endl;
				intN = atoi(str);
				uf = NULL;
				uf = UnionFind(intN + 1);
				intGood = 0;
				intBad = 0;
			}
		}
		else
		{
			cout << intGood << "," << intBad << endl;
			break;
		}
	}
	
	return 0;
}
//======================================================================================================================