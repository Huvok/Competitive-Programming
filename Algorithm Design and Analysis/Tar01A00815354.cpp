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

//															//From a string with duplicate unique characters, get the
//															//		only character that is not duplicated.

//															//Time complexity: O(log(N))
//															//Space complexity: O(1), or O(log(N)) if using the
//															//		recursive version.

//															//Format:
//															//Input
//															//Output

//															//ABB
//															//A

//															//AABBCCD
//															//D

//															//AABBCCDDEEKKFFMJJ
//															//M

//															//aabbkkggiiddmmjjssNNcOOPPLLKKJJHHGGFFDDSSAAZZXXCCxxzzVVvv
//															//c

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	string str;
	cin >> str;

	ll intLow = 0, intHigh = str.length() - 1, intMiddle;
	while (intLow <= intHigh)
	{
		//													//This is the last character and is single, it is the answer
		if (intLow == intHigh)
		{
			cout << str[intLow] << endl;
			break;
		}

		//													//To prevent overflows (instead of the typical l + h / 2)
		intMiddle = (intHigh - intLow) / 2 + intLow;

		//													//If the middle's character couple is to the left...
		if (intMiddle > 0 && str[intMiddle] == str[intMiddle - 1])
		{
			//												//... and the left half is odd, "recurse" there
			if ((intMiddle - 1 - intLow) % 2 == 1)
			{
				intHigh = intMiddle - 2;
			}
			//												//else, "recurse" to the right half
			else
			{
				intLow = intMiddle + 1;
			}
		}
		//													//The same as above, but inverted
		else if (intMiddle < str.length() - 1 && str[intMiddle] == str[intMiddle + 1])
		{
			if ((intHigh - intMiddle - 1) % 2 == 1)
			{
				intLow = intMiddle + 2;
			}
			else
			{
				intHigh = intMiddle - 1;
			}
		}
		//													//If the middle's character has no couple, it is the answer
		else
		{
			cout << str[intMiddle] << endl;
			break;
		}
	}

	return 0;
}
//======================================================================================================================