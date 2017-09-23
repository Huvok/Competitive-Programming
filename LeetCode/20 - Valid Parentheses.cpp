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
class Solution {
public:
	bool isValid(string s)
	{
		stack<char> st;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(' ||
				s[i] == '[' ||
				s[i] == '{') st.push(s[i]);
			else
			{
				if (st.empty())
				{
					st.push('@');
					break;
				}
				if (s[i] == ']' && st.top() != '[') break;
				else if (s[i] == ')' && st.top() != '(') break;
				else if (s[i] == '}' && st.top() != '{') break;
				st.pop();
			}
		}

		if (st.empty()) return true;
		else return false;
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	

	return 0;
}
//======================================================================================================================