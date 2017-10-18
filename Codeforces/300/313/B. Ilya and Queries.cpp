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
ll arr[100005];
ll err[100005];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intQ;
	string str;
	cin >> str;
	scanf("%lld", &intQ);
	FOR(intI, 1, str.length())
	{
		if (str[intI] == str[intI - 1] && str[intI] == '.')
		{
			arr[intI] = arr[intI - 1] + 1;
			err[intI] = err[intI - 1];
		}
		else if (str[intI] == str[intI - 1] && str[intI] == '#')
		{
			err[intI] = err[intI - 1] + 1;
			arr[intI] = arr[intI - 1];
		}
		else
		{
			arr[intI] = arr[intI - 1];
			err[intI] = err[intI - 1];
		}
	}

	ll intL, intR;
	FOR(intI, 0, intQ)
	{
		scanf("%lld %lld", &intL, &intR);
		intL--; intR--;
		ll a = arr[intR] - (intL >= 0 ? arr[intL] : 0);
		ll b = err[intR] - (intL >= 0 ? err[intL] : 0);
		printf("%lld\n", a + b);
	}
	return 0;
}
//======================================================================================================================