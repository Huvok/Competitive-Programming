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
ii arr[500];

bool comp(ii a, ii b)
{
	if (a.first != b.first) return a.first > b.first;
	return a.second < b.second;
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll n, k;
	cin >> n >> k;

	FOR(i, 0, n)
	{
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr, arr + n, comp);

	ll count = 0;
	FOR(i, 0, n)
	{
		if (arr[i] == arr[k - 1])
			count++;
	}
	cout << count << endl;

	return 0;
}

//====================================================================================================================== 