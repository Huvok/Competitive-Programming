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
	vector<vector<string>> groupAnagrams(vector<string>& strs) 
	{
		unordered_map<string, vector<string>> m;
		FOR(intI, 0, strs.size())
		{
			string str = strs[intI];
			sort(str.begin(), str.end());

			if (m.find(str) == m.end())
			{
				vector<string> v;
				v.pb(strs[intI]);
				m.insert(mp(str, v));
			}
			else
			{
				m[str].pb(strs[intI]);
			}
		}

		vector<vector<string>> ans;
		for (auto it : m)
		{
			ans.pb(it.second);
		}

		return ans;
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	
	return 0;
}
//======================================================================================================================