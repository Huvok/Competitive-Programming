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
//															//DESCRIPTION, ANALYSIS AND TEST CASES

//															//You are given N and a string with length N with 0's and
//															//		1's. You can remove a 0 and a 1 if them are
//															//		together; what is the smallest string you can be left
//															//		with?

//															//Time complexity: O(N)
//															//Space complexity: O(1)

//															//Format:
//															//N
//															//String
//															//Output

//															//4
//															//1100
//															//0

//															//5
//															//01010
//															//1

//															//6
//															//11101111
//															//6

//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN;
	cin >> intN;
	string str;
	cin >> str;

	ll intOnes = 0, intZeros = 0;

	//														//The answer is just the absolute difference between 0's and
	//														//		1's.
	FOR(intI, 0, intN)
	{
		if (str[intI] - '0')
		{
			intOnes++;
		}
		else
		{
			intZeros++;
		}
	}

	cout << abs(intOnes - intZeros) << endl;

	return 0;
}
//======================================================================================================================