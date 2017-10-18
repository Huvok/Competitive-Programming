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
class Solution {
public:
	string a, b;
	ll dp[200][200];
	bool isMatch(string s, string p)
	{
		memset(dp, -1, sizeof(dp));
		a = s;
		b = p;
		return solve(0, 0);
	}

	bool solve(ll i, ll j)
	{
		if (dp[i][j] != -1) return dp[i][j];

		if (j == b.length()) return dp[i][j] = i == a.length();

		if (j < b.length() &&
			b[j + 1] == '*')
		{
			return dp[i][j] = (solve(i, j + 2) ||
				((i < a.length() &&
				(a[i] == b[j] ||
					b[j] == '.')) &&
				solve(i + 1, j)));
		}
		else
		{
			return dp[i][j] = (i < a.length() &&
				(a[i] == b[j] ||
					b[j] == '.')) &&
				solve(i + 1, j + 1);
		}
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	Solution sol;
	sol.isMatch("aa", "a*");

	return 0;
}
//======================================================================================================================