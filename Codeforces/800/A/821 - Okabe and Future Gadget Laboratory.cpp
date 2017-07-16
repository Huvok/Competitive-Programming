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
	ll intN, arr[55][55];

	cin >> intN;

	for (ll intI = 0; intI < intN; intI++)
	{
		for (ll intJ = 0; intJ < intN; intJ++)
		{
			cin >> arr[intI][intJ];
		}
	}

	bool can = false;
	bool is = true;
	for (ll intI = 0; intI < intN; intI++)
	{
		for (ll intJ = 0; intJ < intN; intJ++)
		{
			can = false;
			if (arr[intI][intJ] != 1)
			{
				for (ll intK = 0; intK < intN; intK++)
				{
					for (ll intL = 0; intL < intN; intL++)
					{
						if (arr[intI][intJ] == arr[intI][intK] + arr[intL][intJ])
						{
							can = true;
							break;
						}
					}

					if (can) break;
				}

				if (!can)
				{
					is = false;
					cout << "No" << endl;
					return 0;
				}
			}
		}
	}

	if (is) cout << "Yes" << endl;


	return 0;
}
//======================================================================================================================