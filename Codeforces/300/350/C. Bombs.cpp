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
ii pairs[100005];

bool comp(const ii& a, const ii& b)
{
	return (abs(a.first) + abs(a.second) < abs(b.first) + abs(b.second));
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN;
	scanf("%lld", &intN);

	ll intMin = 0;
	FOR(intI, 0, intN)
	{
		scanf("%lld %lld", &pairs[intI].first, &pairs[intI].second);
		if (pairs[intI].first != 0) intMin += 2;
		if (pairs[intI].second != 0) intMin += 2;
		intMin += 2;
	}

	sort(pairs, pairs + intN, comp);

	printf("%lld\n", intMin);
	FOR(intI, 0, intN)
	{
		ii intCur = { 0,0 };
		if (pairs[intI].first < intCur.first)
		{
			printf("1 %lld L\n", abs(pairs[intI].first));
		}
		else if (pairs[intI].first > intCur.first)
		{
			printf("1 %lld R\n", abs(pairs[intI].first));
		}

		intCur.first = pairs[intI].first;

		if (pairs[intI].second < intCur.second)
		{
			printf("1 %lld D\n", abs(pairs[intI].second));
		}
		else if (pairs[intI].second > intCur.second)
		{
			printf("1 %lld U\n", abs(pairs[intI].second));
		}

		intCur.second = pairs[intI].second;

		printf("2\n");

		if (intCur.second < 0)
		{
			printf("1 %lld U\n", abs(intCur.second));
		}
		else if (intCur.second > 0)
		{
			printf("1 %lld D\n", abs(intCur.second));
		}

		intCur.second = 0;

		if (intCur.first < 0)
		{
			printf("1 %lld R\n", abs(intCur.first));
		}
		else if (intCur.first > 0)
		{
			printf("1 %lld L\n", abs(intCur.first));
		}

		intCur.first = 0;

		printf("3\n");
	}

	return 0;
}
//======================================================================================================================