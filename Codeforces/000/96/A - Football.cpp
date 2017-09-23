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
int main()
{
	string str;

	cin >> str;

	char charCurrent = 'k';
	int intCount = 0;
	for (int intI = 0; intI < str.length(); intI++)
	{
		if (intCount >= 7)
		{
			cout << "YES";
			return 0;
		}
		else if (str[intI] != charCurrent)
		{
			intCount = 1;
			charCurrent = str[intI];
		}
		else
		{
			intCount++;
		}
	}

	if (intCount >= 7)
	{
		cout << "YES";
		return 0;
	}

	cout << "NO";

	return 0;
}
//======================================================================================================================