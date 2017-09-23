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
	string str = "!!!!";

	string strIn;
	cin >> strIn;

	FOR(intI, 0, strIn.length())
	{
		if (strIn[intI] != '!') str[intI % 4] = strIn[intI];
	}

	ll arr[30];
	memset(arr, 0, sizeof(arr));
	FOR(intI, 0, strIn.length())
	{
		if (strIn[intI] != str[intI % 4]) arr[str[intI % 4] - 'A']++;
	}

	cout << arr['R' - 'A'] << " " << arr['B' - 'A'] << " " << arr['Y' - 'A'] << " " << arr['G' - 'A'] << endl;

	return 0;
}
//======================================================================================================================