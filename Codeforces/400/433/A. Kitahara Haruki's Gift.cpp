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
#include <unordered_set>

using namespace std;

//															//AUTHOR: Hugo Garcia
//															//PURPOSE: Competitive programming template

//======================================================================================================================

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define pb push_back
#define mp make_pair
#define lld I64d

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll a = 0, b = 0, intN, intNext;

	scanf("%lld", &intN);

	FOR(intI, 0, intN)
	{
		scanf("%lld", &intNext);
		if (intNext == 100) a++;
		else b++;
	}

	if (b % 2 == 0 &&
		a % 2 == 0)
	{
		printf("YES\n");
	}
	else if (b % 2 == 1 &&
		a % 2 == 0 &&
		a >= 2)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}

	return 0;
}

//======================================================================================================================