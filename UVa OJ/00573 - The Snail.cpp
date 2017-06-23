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
	ll intHeight, intUp, intDown, intFatigue, intDay;
	double newUp, intCurrent;
	double ratio;

	while (true)
	{
		cin >> intHeight >> intUp >> intDown >> intFatigue;
		ratio = intUp * intFatigue / 100.0;
		newUp = intUp;
		if (!intHeight) break;

		intCurrent = 0.0;
		intDay = 0;
		while (true)
		{
			intDay++;
			intCurrent += newUp;

			newUp -= ratio;

			if (intCurrent > intHeight)
			{
				cout << "success on day " << intDay << endl;
				break;
			}

			intCurrent -= intDown;
			if (newUp < 0)
			{
				newUp = 0;
			}

			if (intCurrent < 0.0)
			{
				cout << "failure on day " << intDay << endl;
				break;
			}
		}
	}

	return 0;
}
//======================================================================================================================