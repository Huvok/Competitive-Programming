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
ll arr[105][105];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intI, intJ;
	cin >> intI >> intJ;

	for (ll i = 0; i < intI; i++)
	{
		string str;
		cin >> str;

		for (ll j = 0; j < intJ; j++)
		{
			if (str[j] == 'R')
			{
				arr[i][j] = 0;
			}
			else if (str[j] == 'G')
			{
				arr[i][j] = 1;
			}
			else
			{
				arr[i][j] = 2;
			}
		}
	}

	//														//Horizontal
	bool hor = true;
	ll intHeight = -1;
	ll col[3] = { 0 };
	ll intCur;
	for (ll i = 0; i < intI; i++)
	{
		intCur = arr[i][0];

		if (i && intCur != arr[i - 1][0])
		{
			if (col[intCur] == 1)
			{
				hor = false;
				break;
			}
		}

		col[intCur] = 1;

		for (ll j = 0; j < intJ; j++)
		{
			if (j && arr[i][j] != arr[i][j - 1])
			{
				hor = false;
				break;
			}
		}
	}

	if (!col[0] ||
		!col[1] ||
		!col[2])
	{
		hor = false;
	}
	else
	{
		ll intCount = 0;
		ll intLength = 0;
		FOR(i, 0, intI)
		{
			intCount++;
			if (i)
			{
				if (arr[i][0] != arr[i - 1][0])
				{
					if (!intLength)
					{
						intLength = intCount - 1;
						intCount = 1;
					}
					else
					{
						if (intLength != intCount - 1)
						{
							hor = false;
							break;
						}

						intCount = 1;
					}
				}

				if (intCount > intLength &&
					intLength) hor = false;
				if (intCount < intLength &&
					intLength &&
					i == intI - 1) hor = false;
			}
		}
	}

	//														//Vertical
	bool ver = true;
	intHeight = -1;
	col[0] = 0;
	col[1] = 0;
	col[2] = 0;
	intCur;
	for (ll j = 0; j < intJ; j++)
	{
		intCur = arr[0][j];
		if (j && intCur != arr[0][j - 1])
		{
			if (col[intCur] == 1)
			{
				ver = false;
				break;
			}

			if (intHeight == -1) intHeight = j;
			else if (intHeight != j - intHeight)
			{
				ver = false;
				break;
			}
		}

		col[intCur] = 1;

		for (ll i = 0; i < intI; i++)
		{
			if (i && arr[i][j] != arr[i - 1][j])
			{
				ver = false;
				break;
			}
		}
	}

	if (!col[0] ||
		!col[1] ||
		!col[2])
	{
		ver = false;
	}
	else
	{
		ll intCount = 0;
		ll intLength = 0;
		FOR(j, 0, intJ)
		{
			intCount++;
			if (j)
			{
				if (arr[0][j] != arr[0][j - 1])
				{
					if (!intLength)
					{
						intLength = intCount - 1;
						intCount = 1;
					}
					else
					{
						if (intLength != intCount - 1)
						{
							ver = false;
							break;
						}

						intCount = 1;
					}
				}

				if (intCount > intLength &&
					intLength) ver = false;
				if (intCount < intLength &&
					intLength &&
					j == intJ - 1) ver = false;
			}
		}
	}

	if (ver || hor)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}

	return 0;
}
//======================================================================================================================