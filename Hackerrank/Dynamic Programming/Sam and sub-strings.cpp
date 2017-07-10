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
	string str;
	cin >> str;
	ll intSum = str[0] - '0';
	ll intAux = intSum;

	for (ll intI = 1; intI < str.length(); intI++)
	{
		intAux = ((intI + 1) * (str[intI] - '0') + 10 * intAux) % 1000000007;
		intSum = (intSum + intAux) % 1000000007;
	}

	cout << intSum;

	return 0;
}
//======================================================================================================================