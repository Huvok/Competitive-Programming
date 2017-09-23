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

//======================================================================================================================

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN;
	cin >> intN;
	ll intSum1, intSum2;
	intN++;
	intSum1 = (to_string(intN)[0] - '0') + to_string(intN)[1] - '0' + to_string(intN)[2] - '0';
	intSum2 = to_string(intN)[3] - '0' + to_string(intN)[4] - '0' + to_string(intN)[5] - '0';

	while (intSum1 != intSum2)
	{
		intN++;
		intSum1 = to_string(intN)[0] - '0' + to_string(intN)[1] - '0' + to_string(intN)[2] - '0';
		intSum2 = to_string(intN)[3] - '0' + to_string(intN)[4] - '0' + to_string(intN)[5] - '0';
	}

	cout << intN << endl;
	return 0;
}
//======================================================================================================================