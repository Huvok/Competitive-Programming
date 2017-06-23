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

//======================================================================================================================
vector<string> lststrTraduction(3);
void subPrintBraille(char charNumber, ll intLine)
{
	if (charNumber == '0')
	{
		lststrTraduction[0] = ".*";
		lststrTraduction[1] = "**";
		lststrTraduction[2] = "..";
	}
	else if (charNumber == '1')
	{
		lststrTraduction[0] = "*.";
		lststrTraduction[1] = "..";
		lststrTraduction[2] = "..";
	}
	else if (charNumber == '2')
	{
		lststrTraduction[0] = "*.";
		lststrTraduction[1] = "*.";
		lststrTraduction[2] = "..";
	}
	else if (charNumber == '3')
	{
		lststrTraduction[0] = "**";
		lststrTraduction[1] = "..";
		lststrTraduction[2] = "..";
	}
	else if (charNumber == '4')
	{
		lststrTraduction[0] = "**";
		lststrTraduction[1] = ".*";
		lststrTraduction[2] = "..";
	}
	else if (charNumber == '5')
	{
		lststrTraduction[0] = "*.";
		lststrTraduction[1] = ".*";
		lststrTraduction[2] = "..";
	}
	else if (charNumber == '6')
	{
		lststrTraduction[0] = "**";
		lststrTraduction[1] = "*.";
		lststrTraduction[2] = "..";
	}
	else if (charNumber == '7')
	{
		lststrTraduction[0] = "**";
		lststrTraduction[1] = "**";
		lststrTraduction[2] = "..";
	}
	else if (charNumber == '8')
	{
		lststrTraduction[0] = "*.";
		lststrTraduction[1] = "**";
		lststrTraduction[2] = "..";
	}
	else
	{
		lststrTraduction[0] = ".*";
		lststrTraduction[1] = "*.";
		lststrTraduction[2] = "..";
	}

	if (intLine == 1)
	{
		cout << lststrTraduction[0];
	}
	else if (intLine == 2)
	{
		cout << lststrTraduction[1];
	}
	else
	{
		cout << lststrTraduction[2];
	}
}

void subTraduce(vector<string> v)
{
	for (ll intI = 0; intI < v[0].length(); intI += 2)
	{
		if (v[0][intI] == '.' && v[0][intI + 1] == '*' &&
			v[1][intI + 1] == '*')
		{
			cout << "0";
		}
		else if (v[0][intI] == '*' && v[0][intI + 1] == '.' &&
			v[1][intI] == '.' && v[1][intI + 1] == '.')
		{
			cout << "1";
		}
		else if (v[0][intI] == '*' && v[0][intI + 1] == '.' &&
			v[1][intI] == '*' && v[1][intI + 1] == '.')
		{
			cout << "2";
		}
		else if (v[0][intI] == '*' && v[0][intI + 1] == '*' &&
			v[1][intI] == '.' && v[1][intI + 1] == '.')
		{
			cout << "3";
		}
		else if (v[0][intI] == '*' && v[0][intI + 1] == '*' &&
			v[1][intI] == '.' && v[1][intI + 1] == '*')
		{
			cout << "4";
		}
		else if (v[0][intI] == '*' && v[0][intI + 1] == '.' &&
			v[1][intI] == '.' && v[1][intI + 1] == '*')
		{
			cout << "5";
		}
		else if (v[0][intI] == '*' && v[0][intI + 1] == '*' &&
			v[1][intI] == '*' && v[1][intI + 1] == '.')
		{
			cout << "6";
		}
		else if (v[0][intI] == '*' && v[0][intI + 1] == '*' &&
			v[1][intI] == '*' && v[1][intI + 1] == '*')
		{
			cout << "7";
		}
		else if (v[0][intI] == '*' && v[0][intI + 1] == '.' &&
			v[1][intI] == '*' && v[1][intI + 1] == '*')
		{
			cout << "8";
		}
		else
		{
			cout << "9";
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN;
	char charMode;
	string str;
	vector<string> v(3);

	while (true)
	{
		cin >> intN;

		if (!intN) break;

		cin >> charMode;

		if (charMode == 'S')
		{
			cin >> str;

			for (ll intI = 0; intI < intN; ++intI)
			{
				subPrintBraille(str[intI], 1);
				if (intI != intN - 1)
				{
					cout << " ";
				}
			}

			cout << endl;

			for (ll intI = 0; intI < intN; ++intI)
			{
				subPrintBraille(str[intI], 2);
				if (intI != intN - 1)
				{
					cout << " ";
				}
			}

			cout << endl;

			for (ll intI = 0; intI < intN; ++intI)
			{
				subPrintBraille(str[intI], 3);
				if (intI != intN - 1)
				{
					cout << " ";
				}
			}

			cout << endl;
		}
		else
		{
			v.clear();
			v.assign(3, "");

			for (ll intI = 0; intI < intN; ++intI)
			{
				cin >> str;
				v[0] = v[0] + str;
			}

			for (ll intI = 0; intI < intN; ++intI)
			{
				cin >> str;
				v[1] = v[1] + str;
			}

			for (ll intI = 0; intI < intN; ++intI)
			{
				cin >> str;
				v[2] = v[2] + str;
			}

			subTraduce(v);
			cout << endl;
		}
	}

	return 0;
}
//======================================================================================================================