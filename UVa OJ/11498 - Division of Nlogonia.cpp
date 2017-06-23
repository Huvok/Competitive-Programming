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

struct Point
{
	ll intX;
	ll intY;
};

//======================================================================================================================
int main()
{
	ll intN, intA, intB;

	intN = 1;

	while (intN)
	{
		cin >> intN;

		if (!intN) break;

		Point pDiv;
		cin >> pDiv.intX >> pDiv.intY;

		for (ll intI = 0; intI < intN; ++intI)
		{
			cin >> intA >> intB;

			if (intA == pDiv.intX ||
				intA == -1 * pDiv.intX ||
				intB == pDiv.intY ||
				intB == -1 * pDiv.intY)
			{
				cout << "divisa" << endl;
			}
			else if (intA > pDiv.intX &&
				intB > pDiv.intY)
			{
				cout << "NE" << endl;
			}
			else if (intA < pDiv.intX &&
				intB > pDiv.intY)
			{
				cout << "NO" << endl;
			}
			else if (intA < pDiv.intX &&
				intB < pDiv.intY)
			{
				cout << "SO" << endl;
			}
			else
			{
				cout << "SE" << endl;
			}
		}
	}

	return 0;
}
//======================================================================================================================