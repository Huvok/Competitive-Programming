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
	int intN;

	string str;

	cin >> intN;

	for (int intI = 0; intI < intN; intI++)
	{
		cin >> str;

		if (str.length() > 10)
		{
			cout << str[0] << str.length() - 2 << str[str.length() - 1] << endl;
		}
		else
		{
			cout << str << endl;
		}
	}
	
	return 0;
}
//======================================================================================================================