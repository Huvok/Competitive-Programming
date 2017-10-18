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
ll a[505], b[505];
ii pairs[505];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intM;
	scanf("%lld", &intN);
	ll intSumA = 0, intSumB = 0;

	FOR(intI, 1, intN + 1)
	{
		scanf("%lld", &a[intI]);
		intSumA += a[intI];
	}

	scanf("%lld", &intM);
	FOR(intI, 1, intM + 1)
	{
		scanf("%lld", &b[intI]);
		intSumB += b[intI];
	}

	if (intSumA != intSumB)
	{
		printf("NO\n");
		return 0;
	}

	intSumA = 0;

	pairs[0] = mp(0, 0);
	FOR(intI, 1, intM + 1)
	{
		ll intF = pairs[intI - 1].second + 1;
		intSumA = a[intF];

		while (intSumA < b[intI])
		{
			intF++;
			intSumA += a[intF];
		}

		if (intSumA != b[intI])
		{
			printf("NO\n");
			return 0;
		}

		pairs[intI] = mp(pairs[intI - 1].second + 1, intF);
	}

	bool isPossible = true;
	FOR(intI, 1, intM + 1)
	{
		bool possibleSegment = false;
		ll intCur = a[pairs[intI].first];
		if (pairs[intI].first != pairs[intI].second)
		{
			FOR(intJ, pairs[intI].first, pairs[intI].second + 1)
			{
				if (intCur != a[intJ])
				{
					possibleSegment = true;
				}
			}

			isPossible &= possibleSegment;
		}
	}

	if (isPossible)
	{
		printf("YES\n");
		FOR(intI, 1, intM + 1)
		{
			ll intStart = intI - 1;
			ll intF = pairs[intI].first;
			ll intS = pairs[intI].second;
			ll intCur = a[intF];

			FOR(intJ, intF, intS + 1)
			{
				intCur = max(intCur, a[intJ]);
			}

			ll intIndex = intF;

			FOR(intJ, intF + 1, intS + 1)
			{
				if (intCur == a[intJ] &&
					a[intJ - 1] < intCur)
				{
					intIndex = intJ;
					break;
				}
			}

			FOR(intJ, intF, intS)
			{
				if (intCur == a[intJ] &&
					a[intJ + 1] < intCur)
				{
					intIndex = -intJ;
					break;
				}
			}

			if (intIndex < 0)
			{
				intIndex = -intIndex;
				ll intLimit = intIndex - (intF - 1);

				FOR(intJ, intIndex + 1, intS + 1)
				{
					printf("%lld R\n", intStart + intLimit);
				}

				ll intOffset = 0;
				for (ll intJ = intIndex - 1; intJ >= intF; intJ--)
				{
					intOffset++;
					printf("%lld L\n", intStart + intLimit - intOffset + 1);
				}
			}
			else
			{
				ll intLimit = intIndex - (intF - 1);
				ll intOffset = 0;

				for (ll intJ = intIndex - 1; intJ >= intF; intJ--)
				{
					intOffset++;
					printf("%lld L\n", intStart + intLimit - intOffset + 1);
				}

				FOR(intJ, intIndex + 1, intS + 1)
				{
					printf("%lld R\n", intI);
				}
			}
		}
	}
	else
	{
		printf("NO\n");
		return 0;
	}

	return 0;
}
//======================================================================================================================