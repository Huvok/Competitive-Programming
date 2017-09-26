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
ll arr[5000000];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN;
	cin >> intN;
	arr[0] = 1;
	arr[1] = 2;
	ll intGames = 1;
	while (arr[intGames] <= intN)
	{
		intGames++;
		arr[intGames] = arr[intGames - 1] + arr[intGames - 2];
	}

	intGames--;
	cout << intGames << endl;

	return 0;
}
//======================================================================================================================