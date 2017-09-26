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
#include <climits>
#include <unordered_map>

using namespace std;

//															//AUTHOR: Hugo Garcia
//															//PURPOSE: Competitive programming template

//======================================================================================================================

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define pb push_back
#define mp make_pair

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
	string strNew = str;
	strNew[1] = str[2];
	strNew[2] = str[4];
	strNew[3] = str[3];
	strNew[4] = str[1];
	ll intN = atoi(strNew.c_str());
	ll intSum = 1;
	FOR(intI, 0, 5)
	{
		intSum *= intN;
		intSum %= 100000;
	}

	if (intSum < 10000)
	{
		string strFinal = "0";
		if (intSum < 1000) strFinal += "0";
		if (intSum < 100) strFinal += "0";
		if (intSum < 10) strFinal += "0";
		cout << strFinal + to_string(intSum);
	}
	else
	{
		cout << intSum << endl;
	}

	return 0;
}
//======================================================================================================================