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
	ll intN, intM;
	cin >> intN >> intM;
	ll a, b, c;
	FOR(intI, 0, intN) arr[intI] = -1;
	FOR(intI, 0, intM)
	{
		cin >> a >> b >> c;
		a--; b--; c--;
		bool taken[3];
		taken[0] = taken[1] = taken[2] = false;
		if (arr[a] != -1) taken[arr[a]] = true;
		if (arr[b] != -1) taken[arr[b]] = true;
		if (arr[c] != -1) taken[arr[c]] = true;
		
		if (arr[a] != -1)
		{
			if (taken[0])
			{
				arr[b] = 1;
				arr[c] = 2;
			}
			else if (taken[1])
			{
				arr[b] = 0;
				arr[c] = 2;
			}
			else
			{
				arr[b] = 0;
				arr[c] = 1;
			}
		}
		else if (arr[b] != -1)
		{
			if (taken[0])
			{
				arr[a] = 1;
				arr[c] = 2;
			}
			else if (taken[1])
			{
				arr[a] = 0;
				arr[c] = 2;
			}
			else
			{
				arr[a] = 0;
				arr[c] = 1;
			}
		}
		else if (arr[c] != -1)
		{
			if (taken[0])
			{
				arr[a] = 1;
				arr[b] = 2;
			}
			else if (taken[1])
			{
				arr[a] = 0;
				arr[b] = 2;
			}
			else
			{
				arr[a] = 0;
				arr[b] = 1;
			}
		}
		else
		{
			arr[a] = 0;
			arr[b] = 1;
			arr[c] = 2;
		}
	}

	FOR(intI, 0, intN)
	{
		cout << arr[intI] + 1 << " ";
	}

	cout << endl;

	return 0;
}

//======================================================================================================================