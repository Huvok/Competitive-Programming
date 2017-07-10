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

struct Pair
{
	int intMonth;
	double num;
};

//======================================================================================================================
int main()
{
	ll intMonths, intN;
	double intPay, intVal;

	vector<Pair> vec;

	while (true)
	{
		cin >> intMonths >> intPay >> intVal >> intN;
		double intOwes = intVal;
		double numMonthPayment = intVal / intMonths;
		intVal += intPay;
		if (intMonths < 0) return 0;

		vec.clear();
		for (int intI = 0; intI < intN; ++intI)
		{
			Pair p;
			cin >> p.intMonth >> p.num;
			vec.push_back(p);
		}

		int intCurrent = 0;
		for (int intI = 0; intI < intMonths; ++intI)
		{
			intVal *= (1 - vec[intCurrent].num);

			if (intCurrent + 1 < intN &&
				intI + 1 == vec[intCurrent + 1].intMonth)
			{
				intCurrent++;
			}

			if (intOwes < intVal)
			{
				if (intI == 1)
				{
					cout << intI << " month" << endl;
				}
				else
				{
					cout << intI << " months" << endl;
				}
				break;
			}

			if (intI == intMonths - 1)
			{
				cout << intMonths << " months" << endl;
			}

			intOwes -= numMonthPayment;
		}
	}


	return 0;
}
//======================================================================================================================