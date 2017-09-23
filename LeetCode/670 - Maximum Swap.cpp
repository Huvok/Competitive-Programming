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
	int maximumSwap(int num) 
	{
		string str = to_string(num);
		ll arrLast[10] = { 0 };
		FOR(intI, 0, str.length())
		{
			arrLast[str[intI] - '0'] = intI;
		}

		FOR(intI, 0, str.length())
		{
			for (ll intJ = 9; intJ > str[intI] - '0'; intJ--)
			{
				if (arrLast[intJ] > intI)
				{
					char temp = str[intI];
					str[intI] = str[arrLast[intJ]];
					str[arrLast[intJ]] = temp;
					return atoi(str.c_str());
				}
			}
		}

		return num;
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	Solution s;
	s.maximumSwap(21);
	return 0;
}
//======================================================================================================================