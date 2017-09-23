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
ll arr[101][101];

ll gcd(ll a, ll b)
{
	if (b) return gcd(b, a%b);
	return a;
}

int main()
{
	ll intN, intL, intD, intS;
	string str;
	cin >> intN;
	for (int intI = 0; intI < intN; intI++)
	{
		cin >> str;
		intL = 0;
		intD = 0;
		intS = 0;
		for (int intJ = 0; intJ < str.length(); intJ++)
		{
			if ((int)str[intJ] >= 48 && (int)str[intJ] <= 57)
			{
				intD++;
			}
			else if (str[intJ] == '@' ||
				str[intJ] == '?' ||
				str[intJ] == '!')
			{
				intS++;
			}
			else
			{
				intL++;
			}
		}

		if (intL < 4)
		{
			cout << "The last character must be a letter." << endl;
		}
		else if (intD < 4)
		{
			cout << "The last character must be a digit." << endl;
		}
		else if (intS < 2)
		{
			cout << "The last character must be a symbol." << endl;
		}
		else
		{
			cout << "The last character can be any type." << endl;
		}
	}

	return 0;
}
//======================================================================================================================