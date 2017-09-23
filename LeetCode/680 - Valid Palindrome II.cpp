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
class Solution 
{
public:
	bool validPalindromeRange(string s, ll intI, ll intJ)
	{
		while (intI < intJ)
		{
			if (s[intI] != s[intJ]) return false;
			intI++;
			intJ--;
		}

		return true;
	}

	bool validPalindrome(string s) 
	{
		FOR(intI, 0, s.length() / 2)
		{
			if (s[intI] != s[s.length() - 1 - intI])
			{
				return validPalindromeRange(s, intI + 1, s.length() - 1 - intI) ||
					validPalindromeRange(s, intI, s.length() - 2 - intI);
			}
		}

		return true;
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	
	return 0;
}
//======================================================================================================================