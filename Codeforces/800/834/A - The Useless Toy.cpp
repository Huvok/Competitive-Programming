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
	string str1, str2;
	cin >> str1 >> str2;
	ll intN;
	cin >> intN;

	intN %= 4;
	if (intN == 1 && str1 == "^")
	{
		if (str2 == ">")
			cout << "cw" << endl;
		else if (str2 == "<")
		{
			cout << "ccw" << endl;
		}
	}
	else if (intN == 1 && str1 == ">")
	{
		if (str2 == "v")
			cout << "cw" << endl;
		else if (str2 == "^")
		{
			cout << "ccw" << endl;
		}
	}
	else if (intN == 1 && str1 == "v")
	{
		if (str2 == "<")
			cout << "cw" << endl;
		else if (str2 == ">")
		{
			cout << "ccw" << endl;
		}
	}
	else if (intN == 1 && str1 == "<")
	{
		if (str2 == "^")
			cout << "cw" << endl;
		else if (str2 == "v")
		{
			cout << "ccw" << endl;
		}
	}
	else if (intN == 2 && str1 == "^")
	{
		if (str2 == "v")
			cout << "undefined" << endl;
	}
	else if (intN == 2 && str1 == ">")
	{
		if (str2 == "<")
			cout << "undefined" << endl;
	}
	else if (intN == 2 && str1 == "v")
	{
		if (str2 == "^")
			cout << "undefined" << endl;
	}
	else if (intN == 2 && str1 == "<")
	{
		if (str2 == ">")
			cout << "undefined" << endl;
	}
	else if (intN == 3 && str1 == "^")
	{
		if (str2 == "<")
			cout << "cw" << endl;
		else if (str2 == ">")
		{
			cout << "ccw" << endl;
		}
	}
	else if (intN == 3 && str1 == ">")
	{
		if (str2 == "^")
			cout << "cw" << endl;
		else if (str2 == "v")
		{
			cout << "ccw" << endl;
		}
	}
	else if (intN == 3 && str1 == "v")
	{
		if (str2 == ">")
			cout << "cw" << endl;
		else if (str2 == "<")
		{
			cout << "ccw" << endl;
		}
	}
	else if (intN == 3 && str1 == "<")
	{
		if (str2 == "v")
			cout << "cw" << endl;
		else if (str2 == "^")
		{
			cout << "ccw" << endl;
		}
	}
	else
	{
		cout << "undefined" << endl;
	}

	return 0;
}
//======================================================================================================================