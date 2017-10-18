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
bool arr[3005];
//----------------------------------------------------------------------------------------------------------------------
int main()
{
	memset(arr, false, sizeof(arr));
	ll intN, intNext;
	cin >> intN;

	FOR(intI, 0, intN)
	{
		cin >> intNext;
		arr[intNext] = true;
	}

	FOR(intI, 1, intN + 2)
	{
		if (arr[intI] == false)
		{
			cout << intI << endl;
			break;
		}
	}

	return 0;
}
//======================================================================================================================