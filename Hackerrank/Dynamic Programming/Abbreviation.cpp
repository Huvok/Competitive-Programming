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

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

//======================================================================================================================
bool isUpper(char c) 
{
	return (c >= 'A') && (c <= 'Z');
}

char toUpper(char c)
{
	if (isUpper(c)) return c;
	return (char)(c - 32);
}

bool dp[1005][1005];
//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intT;
	cin >> intT;

	string str1, str2;
	while (intT--)
	{
		cin >> str1;
		cin >> str2;

		memset(dp, 0, sizeof dp);
		dp[0][0] = true;

		for (ll intI = 0; intI < str1.length(); intI++)
		{
			for (ll intJ = 0; intJ <= str2.length(); intJ++)
			{
				if (dp[intI][intJ])
				{
					if (intJ < str2.length() &&
						toUpper(str1[intI]) == str2[intJ])
					{
						dp[intI + 1][intJ + 1] = true;
					}

					if (!isUpper(str1[intI]))
					{
						dp[intI + 1][intJ] = true;
					}
				}
			}
		}

		if (dp[str1.length()][str2.length()])
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}

	return 0;
}
//======================================================================================================================