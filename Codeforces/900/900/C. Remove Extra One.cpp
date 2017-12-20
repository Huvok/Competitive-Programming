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
ll arr[100005], quantity[100005];

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll n;
	scanf("%lld", &n);
	ll initial = 0;
	FOR(i, 0, n)
	{
		scanf("%lld", &arr[i]);
	}

	ll biggest = -1, biggest2 = -1;

	quantity[arr[0]]--;
	if (n > 1 &&
		arr[0] > arr[1]) quantity[arr[0]]++;
	FOR(i, 0, n)
	{
		if (arr[i] > biggest &&
			biggest != -1)
		{
			quantity[arr[i]]--;
		}

		if (arr[i] < biggest &&
			arr[i] > biggest2 &&
			biggest != -1 &&
			biggest2 != -1)
		{
			quantity[biggest]++;
		}

		if (arr[i] > biggest)
		{
			biggest2 = biggest;
			biggest = arr[i];
		}
		else if (arr[i] > biggest2)
			biggest2 = arr[i];
	}

	ll champ = 0;
	FOR(i, 1, n + 1)
	{
		champ = max(champ, quantity[i]);
	}

	ll intChamp = INT_MAX;
	FOR(i, 1, n + 1)
	{
		if (quantity[i] == champ)
		{
			intChamp = min(intChamp, i);
		}
	}

	if (intChamp == INT_MAX)
		intChamp = 1;

	printf("%lld\n", intChamp);
	return 0;
}

//======================================================================================================================  