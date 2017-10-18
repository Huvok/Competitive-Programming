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
	ll intN;
	cin >> intN;

	ll intMax = -1;
	string str = "";
	FOR(intI, 0, intN * 2 + 1)
	{
		str = "";
		if (intI > intN) intMax--;
		else intMax++;
		FOR(intJ, 0, intN * 2 + 1)
		{
			if (intJ < intN - intMax)
			{
				str += "  ";
			}
			else
			{
				if (intJ <= intN)
				{
					str += to_string(intMax - (intN - intJ)) + " ";
				}
				else if (intJ > intN &&
					intMax - (intJ - intN) >= 0)
				{
					str += to_string(intMax - (intJ - intN)) + " ";
				}
				else break;
			}
		}

		cout << str.substr(0, str.length() - 1) << endl;
	}

	return 0;
}
//======================================================================================================================