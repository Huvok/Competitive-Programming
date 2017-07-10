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

using namespace std;

//															//AUTHOR: Hugo Garcia
//															//PURPOSE: Competitive programming template

//======================================================================================================================

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

//======================================================================================================================

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intT;

	scanf("%lld", &intT);

	while (intT--)
	{
		bool arr[26] = { 0 };
		ll intE = 0, intV = 0;
		string str;
		while (true)
		{
			cin >> str;
			if (str[0] == '*') break;

			arr[(int)str[1] - 65] = arr[(int)str[3] - 65] = true;
			intE++;
		}

		cin >> str;
		ll intAcorns = 0;
		for (ll intI = 0; intI < str.length(); intI += 2)
		{
			if (arr[(int)str[intI] - 65] == false)
			{
				intAcorns++;
			}

			intV++;
		}

		cout << "There are " << intV - intE - intAcorns << " tree(s) and " << intAcorns << " acorn(s)." << endl;
	}

	return 0;
}
//======================================================================================================================