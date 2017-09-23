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
using namespace std;

map<string, ll> m; 
pair<ll, ll> ed[1005];
bool edge[1005][1005];
ll dp[1005];
ll intN, intT, intK;

ll solve() 
{
	ll intRes = 0;
	dp[0] = 0;

	FOR(intI, 0, intN + 1)
	{
		FOR(intJ, 0, intI)
		{
			if (edge[intJ][intI] && dp[intJ] != -1) 
			{
				dp[intI] = max(dp[intI], dp[intJ] + 1);
			}
		}

		intRes = max(intRes, dp[intI]);
	}
	return intRes;
}

ll add(const string &str) 
{
	if (m.count(str) == 0) 
	{
		m[str] = (ll)m.size() + 1;
	}

	return m[str];
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intT;

	scanf("%lld", &intT);
	while (intT--)
	{
		memset(dp, -1, sizeof(dp));
		memset(edge, 0, sizeof(edge));
		m.clear();
		scanf("%lld %lld", &intN, &intK);
		char c[1005];
		scanf("%s", c);
		string str = c;
		str = str.substr(str.length() - intK, intK);
		sort(str.begin(), str.end());
		ed[0].second = add(str);
		
		FOR(intI, 1, intN + 1)
		{
			string a, b;
			scanf("%s", c);
			a = c;
			b = a.substr(a.length() - intK, intK);
			a = a.substr(0, intK);

			sort(a.begin(), a.end());
			sort(b.begin(), b.end());

			ed[intI].first = add(a);
			ed[intI].second = add(b);

			FOR(intJ, 0, intI)
			{
				if (ed[intJ].second == ed[intI].first)
				{
					edge[intJ][intI] = true;
				}

			}
		}

		printf("%lld\n", solve());
	}

	return 0;
}
//======================================================================================================================