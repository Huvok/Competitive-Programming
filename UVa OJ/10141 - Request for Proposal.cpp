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
	ll intN, intP, intReqMet, intCount = 0;
	double numPrice, numChamp, numRatioChamp;
	string strLine, strName, strChamp;

	while (true)
	{
		cin >> intN >> intP;
		intCount++;
		if (intN == 0 && intP == 0) break;

		for (ll intI = 0; intI <= intN; ++intI)
		{
			getline(cin, strLine);
		}

		for (ll intI = 0; intI < intP; ++intI)
		{
			getline(cin, strName);

			cin >> numPrice >> intReqMet;

			for (ll intJ = 0; intJ <= intReqMet; ++intJ)
			{
				getline(cin, strLine);
			}

			if (intI == 0)
			{
				numChamp = numPrice;
				strChamp = strName;
				numRatioChamp = (intReqMet * 1.0) / intN;
			}
			else
			{
				if ((intReqMet * 1.0) / intN > numRatioChamp)
				{
						numChamp = numPrice;
						strChamp = strName;
						numRatioChamp = (intReqMet * 1.0) / intN;
				}
				else if ((intReqMet * 1.0) / intN == numRatioChamp)
				{
					if (numChamp > numPrice)
					{
						numChamp = numPrice;
						strChamp = strName;
						numRatioChamp = (intReqMet * 1.0) / intN;
					}
				}
			}
		}

		if (intCount > 1) cout << endl;
		cout << "RFP #" << intCount << endl;
		cout << strChamp << endl;
	}

	return 0;
}
//======================================================================================================================