﻿#include <cmath>
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
#include <limits.h>

using namespace std;

//															//AUTHOR: Hugo Garcia
//															//PURPOSE: Competitive programming template

//======================================================================================================================

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define RFOR(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define pb push_back
#define mp make_pair
#define lld I64d
#define all(a) (a).begin(), (a).end()
#define ifile(a) freopen((a), "r", stdin)
#define ofile(a) freopen((a), "w", stdout)
#define sync ios_base::sync_with_stdio(false)

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

using namespace std;

//----------------------------------------------------------------------------------------------------------------------
ll arr[105];

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	int n, m;
	cin >> n >> m;
	int a, b;
	arr[0] = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		for (int j = a + 1; j <= b; j++)
		{
			arr[j] = 1;
		}
	}

	for (int i = 0; i <= m; i++)
	{
		if (arr[i] == false)
		{
			cout << "NO" << endl;
			break;
		}

		if (i == m)
		{
			cout << "YES" << endl;
		}
	}

	return 0;
}

//====================================================================================================================== 