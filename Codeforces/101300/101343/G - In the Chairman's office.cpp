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

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
ll arr[101][101];

ll gcd(ll a, ll b)
{
	if (b) return gcd(b, a%b);
	return a;
}

int main()
{
	ll intN, intM;
	cin >> intN >> intM;

	if (intM % intN == 0)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}


	return 0;
}
//======================================================================================================================