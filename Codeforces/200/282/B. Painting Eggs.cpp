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
ii arr[1000005];
char str[1000005];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN;
	scanf("%lld", &intN);

	FOR(intI, 0, intN)
	{
		scanf("%lld %lld", &arr[intI].first, &arr[intI].second);
	}

	ll intCur = 0;

	FOR(intI, 0, intN)
	{
		if (intCur + arr[intI].first <= 500)
		{
			str[intI] = 'A';
			intCur += arr[intI].first;
		}
		else if (intCur - arr[intI].second >= -500)
		{
			str[intI] = 'G';
			intCur -= arr[intI].second;
		}
		else
		{
			printf("-1\n");
			return 0;
		}
	}

	printf("%s\n", str);
	return 0;
}
//======================================================================================================================