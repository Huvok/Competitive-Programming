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
vi AdjList[100005];
bool vis[100005];

double solve(ll intNow)
{
	vis[intNow] = true;
	double intRet = 0;
	ll intVis = AdjList[intNow].size();
	FOR(intI, 0, AdjList[intNow].size())
	{
		if (vis[AdjList[intNow][intI]])
			intVis--;
	}
	FOR(intI, 0, AdjList[intNow].size())
	{
		if (!vis[AdjList[intNow][intI]])
			intRet += solve(AdjList[intNow][intI]) + 1;
	}
	vis[intNow] = false;
	return (intRet) / (intVis > 0 ? intVis : 1.0);
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN;
	cin >> intN;
	ll intS, intD;
	memset(vis, false, sizeof(vis));
	FOR(intI, 0, intN - 1)
	{
		cin >> intS >> intD;
		AdjList[intS].pb(intD);
		AdjList[intD].pb(intS);
	}

	cout << fixed << setprecision(10) << solve(1) << endl;

	return 0;
}
//======================================================================================================================