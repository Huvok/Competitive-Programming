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
	transform(str.begin(), str.end(), str.begin(), ::tolower);

	string strNew = "";

	for (int intI = 0; intI < str.length(); intI++)
	{
		if (str[intI] != 'a' &&
			str[intI] != 'e' &&
			str[intI] != 'i' &&
			str[intI] != 'o' &&
			str[intI] != 'u' &&
			str[intI] != 'y')
		{
			strNew = strNew + "." + str[intI];
		}
	}

	cout << strNew << endl;

	return 0;
}
//======================================================================================================================