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

//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intK;
	cin >> intN >> intK;
	string str;
	cin >> str;
	memset(arrLast, -1, sizeof(arrLast));
	memset(arrGuarded, false, sizeof(arrGuarded));

	for (ll intI = intN - 1; intI >= 0; intI--)
	{
		if (arrLast[str[intI] - 65] == -1)
		{
			arrLast[str[intI] - 65] = intI;
		}
	}

	ll intFreeK = intK;
	for (ll intI = 0; intI < intN; intI++)
	{
		if (arrGuarded[str[intI] - 65] == false)
		{
			arrGuarded[str[intI] - 65] = true;
			intFreeK--;
			if (intFreeK < 0)
			{
				cout << "YES" << endl;
				return 0;
			}
		}

		if (arrLast[str[intI] - 65] == intI)
		{
			intFreeK++;
		}
	}

	cout << "NO" << endl;

	return 0;
}
//======================================================================================================================