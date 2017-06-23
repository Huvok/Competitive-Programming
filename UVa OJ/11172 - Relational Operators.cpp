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
typedef unsigned long long ll;

//======================================================================================================================
int main()
{
	ll intN, intA, intB;

	cin >> intN;

	for (int intI = 0; intI < intN; ++intI)
	{
		cin >> intA >> intB;

		if (intA == intB)
		{
			cout << "=" << endl;
		}
		else if (intA > intB)
		{
			cout << ">" << endl;
		}
		else
		{
			cout << "<" << endl;
		}
	}

	return 0;
}
//======================================================================================================================