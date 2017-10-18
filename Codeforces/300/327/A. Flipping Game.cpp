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
ll arr[105];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN;
	cin >> intN;
	FOR(intI, 0, intN) cin >> arr[intI];
	ll intOnes = 0;
	ll intSum = 0;
	ll intChamp = 0;
	FOR(intI, 0, intN)
	{
		if (arr[intI] == 0) intSum++;
		else
		{
			intSum--;
			intOnes++;
		}

		if (intSum < 0)
		{
			intSum = 0;
		}
		else
		{
			intChamp = max(intChamp, intSum);
		}
	}

	cout << (intOnes == intN ? intN - 1 : intChamp + intOnes) << endl;

	return 0;
}

//======================================================================================================================