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
#include <unordered_set>

using namespace std;

//															//AUTHOR: Hugo Garcia
//															//PURPOSE: Competitive programming template

//======================================================================================================================

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define pb push_back
#define mp make_pair
#define lld I64d

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll intT, intX1, intY1, intX2, intY2;

	cin >> intT >> intX1 >> intY1 >> intX2 >> intY2;

	string s;
	cin >> s;
	ll intCur, intNew;
	ll intCount = 0;
	FOR(intI, 0, intT)
	{
		if (intX1 == intX2 && intY1 == intY2) break;
		intCount++;
		intCur = abs(intX1 - intX2) + abs(intY1 - intY2);
		intNew;
		if (s[intI] == 'N')
		{
			intNew = abs(intX1 - intX2) + abs(intY1 + 1 - intY2);
			if (intNew < intCur) intY1++;
		}
		else if (s[intI] == 'E')
		{
			intNew = abs(intX1 + 1 - intX2) + abs(intY1 - intY2);
			if (intNew < intCur) intX1++;
		}
		else if (s[intI] == 'S')
		{
			intNew = abs(intX1 - intX2) + abs(intY1 - 1 - intY2);
			if (intNew < intCur) intY1--;
		}
		else
		{
			intNew = abs(intX1 - 1 - intX2) + abs(intY1 - intY2);
			if (intNew < intCur) intX1--;
		}
	}

	cout << (intX1 == intX2 && intY1 == intY2 ? intCount : -1) << endl;

	return 0;
}

//======================================================================================================================