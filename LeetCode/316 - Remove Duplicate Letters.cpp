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
	string removeDuplicateLetters(string s)
	{
		if (s.length() <= 0) return "";
		ll intChamp = 0;
		ll arrCount[28];
		memset(arrCount, 0, sizeof(arrCount));
		FOR(intI, 0, s.length()) arrCount[s[intI] - 97]++;
		FOR(intI, 0, s.length())
		{
			if (intI)
			{
				if (s[intI] < s[intChamp]) intChamp = intI;
			}
			arrCount[s[intI] - 97]--;
			if (arrCount[s[intI] - 97] == 0) break;
		}

		string strAux = "";
		char champ = s[intChamp];
		s = s.substr(intChamp + 1);
		FOR(intI, 0, s.length())
		{
			if (s[intI] != champ) strAux += s[intI];
		}

		return champ + removeDuplicateLetters(strAux);
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	Solution s;
	cout << s.removeDuplicateLetters("cbacdcbc");
	return 0;
}
//======================================================================================================================