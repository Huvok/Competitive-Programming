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
	string countAndSay(int n)
	{
		if (!n) return "";
		string ans = "1";
		n--;
		while (n--)
		{
			string aux = "";
			for (int i = 0; i < ans.length(); i++)
			{
				int intCount = 1;
				while (i < ans.length() - 1 &&
					ans[i] == ans[i + 1])
				{
					intCount++;
					i++;
				}

				aux += to_string(intCount) + ans[i];
			}

			ans = aux;
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