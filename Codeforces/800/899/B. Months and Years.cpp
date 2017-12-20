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
ll months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
ll arr[30];
ll n;

bool check(ll i)
{
	bool leap = false;
	FOR(j, 0, n)
	{
		if (arr[j] != months[(i + j) % 12])
		{
			if ((i + j) % 12 == 1 &&
				arr[j] == 29 &&
				!leap)
			{
				leap = true;
			}
			else
			{
				return false;
			}
		}
	}

	return true;
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	cin >> n;
	FOR(i, 0, n)
	{
		cin >> arr[i];
	}

	FOR(i, 0, 12)
	{
		if (check(i))
		{
			cout << "YES" << endl;
			break;
		}

		if (i == 11)
		{
			cout << "NO" << endl;
		}
	}

	return 0;
}

//====================================================================================================================== 