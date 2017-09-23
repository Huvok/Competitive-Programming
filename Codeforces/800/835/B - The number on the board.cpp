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
	ll intSum;
	string strNum;
	cin >> intSum;
	cin >> strNum;

	ll digits[10];
	memset(digits, 0, sizeof(digits));
	ll intCur = 0;

	for (ll intI = 0; intI < strNum.length(); intI++)
	{
		digits[strNum[intI] - '0']++;
		intCur += (strNum[intI] - '0');
	}

	ll intRes = 0;
	ll intIndex = 0;

	while (intCur < intSum)
	{
		if (digits[intIndex] > 0)
		{
			digits[intIndex]--;
			intRes++;
			intCur += (9 - intIndex);
		}
		else
		{
			intIndex++;
		}
	}

	cout << intRes << endl;

	return 0;
}
//======================================================================================================================