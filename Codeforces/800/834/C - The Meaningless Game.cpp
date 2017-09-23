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
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
ll cubic_root(ll x)
{
	ll l = 0, r = 1000005;
	while (l != r) {
		ll m = (l + r + 1) / 2;
		if (m * m * m > x)
			r = m - 1;
		else
			l = m;
	}
	return l;
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intT;
	cin >> intT;

	ll intA, intB;
	while (intT--)
	{
		scanf("%lld %lld", &intA, &intB);
		ll intRoot = cubic_root(intA * intB);

		if (intRoot * intRoot * intRoot != intA * intB)
		{
			printf("No\n");
		}
		else if (intA % intRoot == 0 &&
			intB % intRoot == 0)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}

	return 0;
}
//======================================================================================================================