#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>

using namespace std;

//															//AUTHOR: Hugo García
//															//PURPOSE: Competitive programming template

//======================================================================================================================
typedef long long ll;

//======================================================================================================================
int main()
{
	ll intN, arrint[3];

	cin >> intN;

	for (int intI = 0; intI < intN; ++intI)
	{
		cin >> arrint[0] >> arrint[1] >> arrint[2];

		sort(arrint, arrint + 3);

		cout << "Case " << intI + 1 << ": " << arrint[1] << endl;
	}

	return 0;
}
//======================================================================================================================