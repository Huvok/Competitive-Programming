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
ll arr[200005];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	string str1, str2;
	cin >> str1;
	cin >> str2;

	FOR(intI, 0, str1.length())
	{
		cin >> arr[intI];
	}

	ll intL = 0, intH = str1.length();
	ll intMid;
	ll intCur = 0;
	while (intL < intH)
	{
		intMid = ((intH - intL) >> 1) + intL + 1;
		string aux = str1;
		FOR(intI, 0, intMid)
		{
			aux[arr[intI] - 1] = '&';
		}

		intCur = 0;
		FOR(intI, 0, aux.length())
		{
			if (aux[intI] == str2[intCur]) intCur++;
		}

		if (intCur >= str2.length())
		{
			intL = intMid;
		}
		else
		{
			intH = intMid - 1;
		}
	}

	cout << intL << endl;

	return 0;
}
//======================================================================================================================