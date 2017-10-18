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
bool arr[1005];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intV, intE;
	cin >> intV >> intE;
	memset(arr, true, sizeof(arr));
	ll intS, intD;

	FOR(intI, 0, intE)
	{
		cin >> intS >> intD;
		intS--; intD--;
		arr[intS] = false;
		arr[intD] = false;
	}

	ll intCenter = 0;
	FOR(intI, 0, intV)
	{
		if (arr[intI])
		{
			intCenter = intI + 1;
			break;
		}
	}

	cout << intV - 1 << endl;
	FOR(intI, 0, intV)
	{
		if (intI + 1 != intCenter)
		{
			cout << intCenter << " " << intI + 1 << endl;
		}
	}


	return 0;
}

//======================================================================================================================