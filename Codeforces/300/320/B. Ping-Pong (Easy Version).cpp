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

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
ll a[105], b[105];
bool vis[105];
ll intN = 1, intV;
void dfs(ll intA)
{
	vis[intA] = true;
	FOR(intI, 1, intN + 1)
	{
		if (vis[intI])
		{
			continue;
		}
		else if (a[intA] > a[intI] && a[intA] < b[intI])
		{
			dfs(intI);
		}
		else if (b[intA] > a[intI] && b[intA] < b[intI])
		{
			dfs(intI);
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intT, intA, intB;
	cin >> intV;
	FOR(intI, 0, intV)
	{
		cin >> intT >> intA >> intB;

		if (intT == 1)
		{
			a[intN] = intA; b[intN] = intB;
			intN++;
		}
		else
		{
			memset(vis, false, sizeof(vis));
			dfs(intA);
			if (vis[intB])
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}
//======================================================================================================================