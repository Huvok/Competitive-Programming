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

using namespace std;

//															//AUTHOR: Hugo Garcia
//															//PURPOSE: Competitive programming template

//======================================================================================================================

typedef long long ll;
typedef vector<ll> vi;

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
	

	return 0;
}
//======================================================================================================================