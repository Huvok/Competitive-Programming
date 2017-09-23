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

	int arr[3];
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;

	for (int intI = 0; intI < str.length(); intI++)
	{
		if (str[intI] == '1')
		{
			arr[0]++;
		}
		else if (str[intI] == '2')
		{
			arr[1]++;
		}
		else if (str[intI] == '3')
		{
			arr[2]++;
		}
	}

	string strFinal = "";
	for (int intI = 0; intI <= str.length() / 2; intI++)
	{
		if (arr[0] > 0)
		{
			strFinal = strFinal + "1";
			arr[0]--;
		}
		else if (arr[1] > 0)
		{
			strFinal += "2";
			arr[1]--;
		}
		else if (arr[2] > 0)
		{
			strFinal += "3";
			arr[2]--;
		}

		strFinal += "+";
	}

	cout << strFinal.substr(0, strFinal.length() - 1);

	return 0;
}
//======================================================================================================================