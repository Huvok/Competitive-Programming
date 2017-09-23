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

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intA, intB;
	cin >> intN >> intA >> intB;

	ll intX, intY;
	vii v;
	FOR(intI, 0, intN)
	{
		cin >> intX >> intY;
		v.push_back(mp(intX, intY));
	}

	ll intMax = 0;

	FOR(intI, 0, v.size() - 1)
	{
		FOR(intJ, intI + 1, v.size())
		{
			if (v[intI].first <= intA &&
				v[intI].second <= intB)
			{
				if (v[intJ].first <= intA - v[intI].first &&
					v[intJ].second <= intB)
				{
					intMax = max(intMax, v[intI].first * v[intI].second + v[intJ].first * v[intJ].second);
				}

				if (v[intJ].second <= intA - v[intI].first &&
					v[intJ].first <= intB)
				{
					intMax = max(intMax, v[intI].first * v[intI].second + v[intJ].first * v[intJ].second);
				}
			}

			if (v[intI].second <= intA &&
				v[intI].first <= intB)
			{
				if (v[intJ].first <= intA - v[intI].second &&
					v[intJ].second <= intB)
				{
					intMax = max(intMax, v[intI].first * v[intI].second + v[intJ].first * v[intJ].second);
				}

				if (v[intJ].second <= intA - v[intI].second &&
					v[intJ].first <= intB)
				{
					intMax = max(intMax, v[intI].first * v[intI].second + v[intJ].first * v[intJ].second);
				}
			}
			
			if (v[intI].first <= intA &&
				v[intI].second <= intB)
			{
				if (v[intJ].first <= intA &&
					v[intJ].second <= intB - v[intI].second)
				{
					intMax = max(intMax, v[intI].first * v[intI].second + v[intJ].first * v[intJ].second);
				}

				if (v[intJ].second <= intA&&
					v[intJ].first <= intB - v[intI].second)
				{
					intMax = max(intMax, v[intI].first * v[intI].second + v[intJ].first * v[intJ].second);
				}
			}

			if (v[intI].second <= intA &&
				v[intI].first <= intB)
			{
				if (v[intJ].first <= intA &&
					v[intJ].second <= intB - v[intI].first)
				{
					intMax = max(intMax, v[intI].first * v[intI].second + v[intJ].first * v[intJ].second);
				}

				if (v[intJ].second <= intA &&
					v[intJ].first <= intB - v[intI].first)
				{
					intMax = max(intMax, v[intI].first * v[intI].second + v[intJ].first * v[intJ].second);
				}
			}
		}
	}

	cout << intMax << endl;
	
	return 0;
}
//======================================================================================================================