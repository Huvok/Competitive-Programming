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
	ll int2, int4;
	ll intN, intK;
	cin >> intN >> intK;
	int2 = intN * 2;
	int4 = intN;
	ll int1 = 0;

	ll intSoldiers;
	FOR(intI, 0, intK)
	{
		cin >> intSoldiers;
		if (int1 > 0 &&
			intSoldiers == 1)
		{
			int1--;
			intSoldiers = 0;
		}

		if (int4 >= intSoldiers / 4 &&
			intSoldiers > 3)
		{
			int4 -= (intSoldiers / 4);
			intSoldiers %= 4;
		}
		else if (intSoldiers > 3 &&
			int4 > 0)
		{
			intSoldiers -= (4 * int4);
			int4 = 0;
		}

		if (int2 >= intSoldiers / 2 &&
			intSoldiers > 1)
		{
			int2 -= intSoldiers / 2;
			intSoldiers %= 2;
		}
		else if (intSoldiers > 1 &&
			int2 > 0)
		{
			intSoldiers -= (int2 * 2);
			int2 = 0;
		}

		if (intSoldiers == 3 &&
			int4 > 0)
		{
			int4--;
			intSoldiers = 0;
		}

		if (intSoldiers == 2 &&
			int4 > 0)
		{
			int4--;
			intSoldiers = 0;
			int1++;
		}

		if (int1 > 0 &&
			intSoldiers > 0)
		{
			if (int1 >= intSoldiers)
			{
				int1 -= intSoldiers;
				intSoldiers = 0;
			}
			else
			{
				intSoldiers -= int1;
				int1 = 0;
			}
		}

		if (intSoldiers == 1 &&
			int4 > 0)
		{
			int4--;
			intSoldiers = 0;
			int2++;
		}

		if (intSoldiers == 1 &&
			int2 > 0)
		{
			int2--;
			intSoldiers = 0;
		}

		if (intSoldiers > 0)
		{
			cout << "NO" << endl;
			break;
		}

		if (intI == intK - 1)
		{
			cout << "YES" << endl;
		}
	}

	return 0;
}
//======================================================================================================================