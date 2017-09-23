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
	ll intNext, intN;
	cin >> intN;

	string str1, str2;
	cin >> str1 >> str2;

	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());

	ll intCount = intN - 1;
	for (ll intI = intN - 1; intI >= 0; intI--)
	{
		if (str1[intI] <= str2[intCount]) intCount--;
	}

	cout << intCount + 1 << endl;

	intCount = 0;
	FOR(intI, 0, intN)
	{
		if (str2[intI] > str1[intCount]) intCount++;
	}

	cout << intCount << endl;

	return 0;
}
//======================================================================================================================