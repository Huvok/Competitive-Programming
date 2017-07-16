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
	ll int2, int1, int2h;
	ll intN;
	cin >> intN >> int1 >> int2;
	int2h = 0;

	ll intNext, intCount = 0;
	for (ll intI = 0; intI < intN; intI++)
	{
		cin >> intNext;

		if (intNext == 1)
		{
			if (int1)
			{
				int1--;
			}
			else if (int2)
			{
				int2--;
				int2h++;
			}
			else if (int2h)
			{
				int2h--;
			}
			else
			{
				intCount++;
			}
		}
		else
		{
			if (int2)
			{
				int2--;
			}
			else
			{
				intCount += 2;
			}
		}
	}

	cout << intCount << endl;
	return 0;
}
//======================================================================================================================