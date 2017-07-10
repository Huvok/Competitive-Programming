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
typedef pair<int, int> ii;
typedef vector<ii> vii;

//======================================================================================================================

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intT;
	cin >> intT;
	cin.ignore();
	while (intT--)
	{
		string str, name;
		getline(cin, str);
		
		char c;
		for (ll intI = 0; intI < str.length(); intI++)
		{
			if (!intI)
			{
				c = str[intI];
			}
			else if (str[intI] == ' ')
			{
				if ((int)c >= 96)
				{
					c = (char)((int)c - 32);
				}

				cout << c << ". ";
				name = "";
				c = str[intI + 1];
				continue;
			}

			if ((int)str[intI] < 96)
			{
				str[intI] = (char)((int)str[intI] + 32);
			}

			name = name + str[intI];
		}

		name[0] = char((int)name[0] - 32);
		cout << name << endl;
	}

	return 0;
}
//======================================================================================================================