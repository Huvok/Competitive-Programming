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
#include <climits>
#include <unordered_map>

using namespace std;

//															//AUTHOR: Hugo Garcia
//															//PURPOSE: Competitive programming template

//======================================================================================================================

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
ll mat[300065][30];
ll ans[300065];

ll pro(vi v)
{
	ll intRet = v.size() - 1;
	FOR(intJ, 0, 26)
	{
		vi aux;
		aux.clear();
		FOR(intI, 0, v.size())
		{
			if (mat[v[intI]][intJ])
			{
				aux.pb(mat[v[intI]][intJ]);
			}

			if (aux.size() <= 1)
			{
				continue;
			}

			intRet += pro(aux);
		}
	}

	return intRet >= 0 ? intRet : 0;
}

void dfs(ll i, ll j)
{
	vi v;
	FOR(intI, 0, 26)
	{
		if (mat[i][intI])
		{
			v.pb(mat[i][intI]);
		}
	}

	ans[j] += (pro(v) + 1);

	FOR(intI, 0, 26)
	{
		if (mat[i][intI])
		{
			dfs(mat[i][intI], j + 1);
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN;
	scanf("%lld", &intN);
	ll intS, intD;
	char c[5];
	memset(ans, 0, sizeof(ans));
	memset(mat, 0, sizeof(mat));
	FOR(intI, 1, intN)
	{
		scanf("%lld %lld %s", &intS, &intD, c);
		mat[intS][c[0] - 'a'] = intD;
	}

	dfs(1, 1);

	ll intMax = -1, intP = 0;
	FOR(intI, 1, intN + 1)
	{
		if (ans[intI] > intMax)
		{
			intMax = ans[intI];
			intP = intI;
		}
	}

	printf("%lld\n%lld\n", intN - intMax, intP);

	return 0;
}
//======================================================================================================================