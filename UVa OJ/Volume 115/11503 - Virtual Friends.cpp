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
class UnionFind
{
private:
	vi p, rank;

public:
	vi size;
	UnionFind(ll N)
	{
		rank.assign(N, 0);
		p.assign(N, 0);
		size.assign(N, 1);

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
				size[x] += size[y];
			}
			else
			{
				p[x] = y;
				size[y] += size[x];

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
	ll intT, intN;
	scanf("%lld", &intT);

	while (intT--)
	{
		scanf("%lld", &intN);
		UnionFind uf = UnionFind(intN * 2);

		unordered_map<string, ll> m;
		string str1, str2;
		ll intCount = 0;
		for (ll intI = 0; intI < intN; intI++)
		{
			cin >> str1 >> str2;
			if (m.find(str1) == m.end())
			{
				m.insert(make_pair(str1, intCount));
				intCount++;
			}

			if (m.find(str2) == m.end())
			{
				m.insert(make_pair(str2, intCount));
				intCount++;
			}

			uf.unionSet(m[str1], m[str2]);

			cout << uf.size[uf.findSet(m[str1])] << endl;
		}
	}

	return 0;
}
//======================================================================================================================