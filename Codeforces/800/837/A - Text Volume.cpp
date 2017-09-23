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
	ll intMax = 0;
	string str;

	string intN;
	getline(cin, intN);
	getline(cin, str);

	ll intCur = 0;
	for (ll intI = 0; intI < str.length(); intI++)
	{
		if (str[intI] == ' ') intCur = 0;
		else if (str[intI] < 93) intCur++;

		intMax = max(intMax, intCur);
	}

	cout << intMax << endl;

	return 0;
}
//======================================================================================================================