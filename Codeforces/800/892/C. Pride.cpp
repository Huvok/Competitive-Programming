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
#include <limits.h>

using namespace std;

//															//AUTHOR: Hugo Garcia
//															//PURPOSE: Competitive programming template

//======================================================================================================================

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define RFOR(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define pb push_back
#define mp make_pair
#define lld I64d
#define all(a) (a).begin(), (a).end()
#define ifile(a) freopen((a), "r", stdin)
#define ofile(a) freopen((a), "w", stdout)
#define sync ios_base::sync_with_stdio(false)

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
ll gcd(ll a, ll b) 
{
	if (b) return gcd(b, a % b);
	return a;
}

ll arr[2005];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN;
	scanf("%lld", &intN);
	ll intOnes = 0;
	FOR(intI, 0, intN)
	{
		scanf("%lld", &arr[intI]);
		if (arr[intI] == 1) intOnes++;
	}

	if (intOnes)
	{
		printf("%lld\n", intN - intOnes);
	}
	else
	{
		ll intBest = INT_MAX;
		FOR(intI, 0, intN - 1)
		{
			ll intCur;
			FOR(intJ, intI + 1, intN)
			{
				if (intJ == intI + 1)
				{
					intCur = gcd(arr[intI], arr[intJ]);
				}
				else
				{
					intCur = gcd(intCur, arr[intJ]);
				}

				if (intCur == 1)
				{
					intBest = min(intBest, intJ - intI + intN - 1);
					break;
				}
			}
		}

		if (intBest == INT_MAX)
		{
			printf("-1\n");
		}
		else
		{
			printf("%lld\n", intBest);
		}
	}

	return 0;
}

//======================================================================================================================