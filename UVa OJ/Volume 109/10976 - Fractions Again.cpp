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

//======================================================================================================================

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intK;
	vii v;

	while (scanf("%lld", &intK) == 1)
	{
		v.clear();
		ll intCount = 0;

		for (ll intI = intK + 1; intI <= intK * 2; intI++)
		{
			if (intK * intI % (intI - intK) == 0)
			{
				intCount++;
				v.push_back(make_pair(intI, intK * intI / (intI - intK)));
			}
		}

		cout << intCount << endl;
		for (ll intI = 0; intI < intCount; intI++)
		{
			cout << "1/" << intK << " = 1/" << v[intI].second << " + 1/" << v[intI].first << endl;
		}
	}

	return 0;
}
//======================================================================================================================