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
	ll intN, intK, intQ, intP, intD;
	cin >> intN >> intK;
	vector<vector<ll>> arr;
	vector <ll> aux;
	for (ll intI = 0; intI < intN; intI++)
	{
		cin >> intQ >> intP;
		arr.push_back(aux);
		arr[intI].push_back(intI);
		arr[intI].push_back(intQ);
		arr[intI].push_back(intP);

		if (intP - intQ > 0 && intQ * 2 < intP)
		{
			arr[intI].push_back(intQ);
		}
		else
		{
			arr[intI].push_back(intP - intQ);
		}
		aux.clear();
	}
	std::sort(arr.begin(), arr.end(),
		[](const std::vector<ll>& a, const std::vector<ll>& b) {
		return a[3] > b[3];
	});

	ll intCount = 0;
	for (ll intI = 0; intI < intN; intI++)
	{
		if (intK > 0)
		{
			if (arr[intI][1] * 2 - arr[intI][2] >= 0)
			{
				intCount += arr[intI][2];
			}
			else
			{
				intCount += (arr[intI][1] * 2);
			}

			if (arr[intI][1] != 0)
				intK--;
		}
		else
		{
			if (arr[intI][1] - arr[intI][2] >= 0)
			{
				intCount += arr[intI][2];
			}
			else
			{
				intCount += arr[intI][1];
			}
		}
	}

	cout << intCount << endl;

	return 0;
}
//======================================================================================================================