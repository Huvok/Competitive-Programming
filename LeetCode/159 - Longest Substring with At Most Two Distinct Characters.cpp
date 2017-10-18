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

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
class Solution
{
public:
	int lengthOfLongestSubstringTwoDistinct(string s)
	{
		if (s == "") return 0;
		int arr[256];
		for (int i = 0; i < 256; i++) arr[i] = 0;
		int intStart = 0, intLength = 1, intCount = 0;
		for (int i = 0; i < s.length(); i++)
		{
			arr[s[i]]++;
			if (arr[s[i]] == 1)
			{
				intCount++;

				while (intCount > 2)
				{
					arr[s[intStart]]--;

					if (arr[s[intStart]] == 0) intCount--;
					intStart++;
				}
			}

			intLength = max(intLength, i - intStart + 1);
		}

		return intLength;
	}
};

//----------------------------------------------------------------------------------------------------------------------

int main()
{

	return 0;
}
//======================================================================================================================