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
ll arr[100005], sum[100005], sorted[100005], sortedSum[100005];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN;
	cin >> intN;
	FOR(intI, 0, intN) 
	{
		cin >> arr[intI];
		sorted[intI] = arr[intI];
	}
	
	sort(sorted, sorted + intN);

	FOR(intI, 0, intN)
	{
		if (intI)
		{
			sum[intI] = sum[intI - 1] + arr[intI];
			sortedSum[intI] = sortedSum[intI - 1] + sorted[intI];
		}
		else
		{
			sum[intI] = arr[intI];
			sortedSum[intI] = sorted[intI];
		}
	}

	ll intQ, intM, intL, intR;

	cin >> intM;
	FOR(intI, 0, intM)
	{
		cin >> intQ >> intL >> intR;

		if (intQ == 1)
		{
			if (intL > 1) cout << (sum[intR - 1] - sum[intL - 2]) << endl;
			else cout << sum[intR - 1] << endl;
		}
		else
		{
			if (intL > 1) cout << (sortedSum[intR - 1] - sortedSum[intL - 2]) << endl;
			else cout << sortedSum[intR - 1] << endl;
		}
	}

	return 0;
}
//======================================================================================================================