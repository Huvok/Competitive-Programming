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
#include <climits>
#include <unordered_map>

using namespace std;

//															//AUTHOR: Hugo Garcia
//															//PURPOSE: Competitive programming template

//======================================================================================================================

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
map<string, ll> s;
struct t4 
{
	ll fi, se, th, fo, points;
};
t4 arr[100005];
ll mat[505][505];

bool comp(t4 a, t4 b) {
	return a.points > b.points;
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intK;
	string a, b, c, d;

	while (scanf("%lld %lld", &intN, &intK))
	{
		if (intN == 0 && intK == 0) break;
		FOR(intI, 0, intK)
		{
			scanf("%lld %lld\n%lld %lld\n%lld", &arr[intI].fi, &arr[intI].se, &arr[intI].fo, &arr[intI].th, &arr[intI].points);
		}

		sort(arr, arr + intK, comp);

		FOR(intI, 0, intN)
		{
			FOR(intJ, 0, intN)
			{
				scanf("%lld", &mat[intI][intJ]);
			}
		}

		for (ll i = 0; i < intN; i += 2)
		{
			for (ll j = 0; j < intN; j += 2)
			{
				s[to_string(mat[i][j]) + " " + to_string(mat[i][j + 1]) + " " + to_string(mat[i + 1][j + 1]) + " " +
					to_string(mat[i + 1][j])]++;
				s[to_string(mat[i][j + 1]) + " " + to_string(mat[i + 1][j + 1]) + " " + to_string(mat[i + 1][j]) + " " +
					to_string(mat[i][j])]++;
				s[to_string(mat[i + 1][j + 1]) + " " + to_string(mat[i + 1][j]) + " " + to_string(mat[i][j]) + " " +
					to_string(mat[i][j + 1])]++;
				s[to_string(mat[i + 1][j]) + " " + to_string(mat[i][j]) + " " + to_string(mat[i][j + 1]) + " " +
					to_string(mat[i + 1][j + 1])]++;
			}
		}

		ll intSum = 0;
		FOR(intI, 0, intK)
		{
			a = to_string(arr[intI].fi) + " " + to_string(arr[intI].se) + " " + to_string(arr[intI].th) + " " +
				to_string(arr[intI].fo);
			b = to_string(arr[intI].se) + " " + to_string(arr[intI].th) + " " + to_string(arr[intI].fo) + " " +
				to_string(arr[intI].fi);
			c = to_string(arr[intI].th) + " " + to_string(arr[intI].fo) + " " + to_string(arr[intI].fi) + " " +
				to_string(arr[intI].se);
			d = to_string(arr[intI].fo) + " " + to_string(arr[intI].fi) + " " + to_string(arr[intI].se) + " " +
				to_string(arr[intI].th);
			if (s.find(a) != s.end() ||
				s.find(b) != s.end() ||
				s.find(c) != s.end() ||
				s.find(d) != s.end())
			{
				intSum += arr[intI].points;
				s[a]--;
				s[b]--;
				s[c]--;
				s[d]--;
				if (!s[a]) s.erase(a);
				if (!s[b]) s.erase(b);
				if (!s[c]) s.erase(c);
				if (!s[d]) s.erase(d);
			}
		}

		if (s.size() == 0)
		{
			printf("%lld\n", intSum);
		}
		else
		{
			printf("-1\n");
		}
	}
	
	return 0;
}
//======================================================================================================================