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
ll arr[100005];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intQ;
	cin >> intN >> intQ;

	FOR(intI, 0, intN) cin >> arr[intI];
	ll intSum = 0;

	FOR(intI, 0, intQ)
	{
		ll intA, intB, intC;
		cin >> intA;
		if (intA == 1)
		{
			cin >> intB >> intC;
			arr[intB - 1] = intC - intSum;
		}
		else if (intA == 2)
		{
			cin >> intB;
			intSum += intB;
		}
		else
		{
			cin >> intB;
			cout << arr[intB - 1] + intSum << endl;
		}
	}

	return 0;
}

//======================================================================================================================