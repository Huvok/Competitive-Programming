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
ii arr[105];

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll n;
	cin >> n;
	ll a = 0, b = 0;
	FOR(i, 0, n)
	{
		cin >> arr[i].first >> arr[i].second;
		a += arr[i].first;
		b += arr[i].second;
	}

	if (a % 2 == 1 &&
		b % 2 == 1)
	{
		FOR(i, 0, n)
		{
			if (arr[i].first % 2 == 0 &&
				arr[i].second % 2 == 1)
			{
				cout << 1 << endl;
				break;
			}
			else if (arr[i].first % 2 == 1 &&
				arr[i].second % 2 == 0)
			{
				cout << 1 << endl;
				break;
			}

			if (i == n - 1)
			{
				cout << -1 << endl;
			}
		}
	}
	else if (a % 2 == 0 &&
		b % 2 == 0)
	{
		cout << 0;
	}
	else
		cout << -1;

	return 0;
}

//====================================================================================================================== 