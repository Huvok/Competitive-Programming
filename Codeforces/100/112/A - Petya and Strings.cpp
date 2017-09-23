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

	cin >> str1;
	cin >> str2;

	transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
	transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

	for (int intI = 0; intI < str1.length(); intI++)
	{
		if ((int)str1[intI] >(int)str2[intI])
		{
			cout << 1;
			return 0;
		}
		else if ((int)str1[intI] < (int)str2[intI])
		{
			cout << -1;
			return 0;
		}
	}

	cout << 0;

	return 0;
}
//======================================================================================================================