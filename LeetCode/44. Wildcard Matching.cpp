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
class Solution
{
public:
	bool isMatch(string s, string p)
	{
		ll intS = 0, intP = 0, intStar = -1, intMatched = 0;

		while (intS < s.length())
		{
			if (s[intS] == p[intP] ||
				p[intP] == '?')
			{
				intS++; intP++;
			}
			else if (p[intP] == '*')
			{
				intStar = intP;
				intP++;
				intMatched = intS;
			}
			else if (intStar != -1)
			{
				intP = intStar + 1;
				intMatched++;
				intS = intMatched;
			}
			else return false;
		}

		while (intP < p.length() &&
			p[intP] == '*') intP++;

		return intP == p.length();
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	Solution sol;
	sol.isMatch("aa", "a");
	return 0;
}
//======================================================================================================================