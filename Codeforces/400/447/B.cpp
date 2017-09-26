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
ll arr[26];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	string str;
	cin >> str;
	ll intK;
	cin >> intK;

	ll intMax = 0;
	FOR(intI, 0, 26)
	{
		cin >> arr[intI];
		intMax = max(arr[intI], intMax);
	}

	ll intSum = 0;

	FOR(intI, 0, str.length())
	{
		intSum += (arr[str[intI] - 'a'] * (intI + 1));
	}

	ll intCur = str.length() + 1;

	FOR(intI, 0, intK)
	{
		intSum += (intMax * intCur);
		intCur++;
	}
	cout << intSum << endl;
	return 0;
}
//======================================================================================================================