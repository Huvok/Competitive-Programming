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
	string str;

	while (intT--)
	{
		str = "";
		cin >> str;

		ll intAux = 0;
		char c;
		ll intL = 0, intR = 0;

		for (ll intI = 0; intI < str.length(); intI++)
		{
			if (!intI)
			{
				c = str[intI];
				if (c == '>')
				{
					intAux--;
				}
				else if (c == '<')
				{
					intAux++;
				}
			}
			else
			{
				if (str[intI] != c &&
					str[intI] != '=')
				{
					if (c == '=')
					{
						c = str[intI];
						if (c == '>')
						{
							intAux--;
						}
						else
						{
							intAux++;
						}

						intL = min(intL, intAux);
						intR = max(intR, intAux);

						continue;
					}
					c = str[intI];
					if (c == '>')
					{
						intAux = intR - 1;
					}
					else
					{
						intAux = intL + 1;
					}
				}
				else if (str[intI] != '=')
				{
					c = str[intI];
					if (c == '>')
					{
						intAux--;
					}
					else
					{
						intAux++;
					}
				}
			}

			intL = min(intL, intAux);
			intR = max(intR, intAux);
		}
		
		cout << abs(intL) + intR  + 1 << endl;
	}

	return 0;
}
//======================================================================================================================