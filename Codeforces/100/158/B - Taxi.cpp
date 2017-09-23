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
	int intN, intCount = 0, intNext;
	cin >> intN;
	int arr[3];
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;

	for (int intI = 0; intI < intN; intI++)
	{
		cin >> intNext;

		if (intNext == 4)
		{
			intCount++;
		}
		else if (intNext == 3)
		{
			arr[2]++;
		}
		else if (intNext == 2)
		{
			arr[1]++;
		}
		else
		{
			arr[0]++;
		}
	}

	while (arr[0] > 0 ||
		arr[1] > 0 ||
		arr[2] > 0)
	{
		if (arr[2] > 0 &&
			arr[0] > 0)
		{
			arr[2]--;
			arr[0]--;
			intCount++;
		}
		else if (arr[2] > 0)
		{
			intCount++;
			arr[2]--;
		}
		else if (arr[1] > 1)
		{
			arr[1] = arr[1] - 2;
			intCount++;
		}
		else if (arr[1] > 0 &&
			arr[0] > 1)
		{
			arr[1]--;
			arr[0]--;
			arr[0]--;
			intCount++;
		}
		else if (arr[1] > 0 &&
			arr[0] > 0)
		{
			arr[1]--;
			arr[0]--;
			intCount++;
		}
		else if (arr[1] > 0)
		{
			arr[1]--;
			intCount++;
		}
		else if (arr[0] > 0)
		{
			intCount = intCount + arr[0] / 4;
			arr[0] = arr[0] % 4;
			if (arr[0] > 0)
			{
				intCount++;
				arr[0] = 0;
			}
		}
	}

	cout << intCount;

	return 0;
}
//======================================================================================================================