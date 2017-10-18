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
ll arr[105][105];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN;
	cin >> intN;

	FOR(intI, 1, intN + 1)
	{
		string str;
		cin >> str;
		FOR(intJ, 0, intN)
		{
			if (str[intJ] == 'x')
			{
				arr[intI][intJ + 1] = 0;
			}
			else
			{
				arr[intI][intJ + 1] = 1;
			}
		}
	}

	FOR(intI, 1, intN + 1)
	{
		FOR(intJ, 1, intN + 1)
		{
			if ((arr[intI - 1][intJ] + arr[intI][intJ + 1] +
				arr[intI + 1][intJ] + arr[intI][intJ - 1]) % 2 == 1)
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	}

	cout << "YES" << endl;
	return 0;
}
//======================================================================================================================