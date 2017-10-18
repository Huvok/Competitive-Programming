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
ii arr[3005];

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intV;

	cin >> intN >> intV;
	ll intSum = 0, intFirst = 0, intSecond = 0;
	FOR(intI, 0, intN)
	{
		cin >> arr[intI].first >> arr[intI].second;
	}

	sort(arr, arr + intN);

	ll intCur = 0;
	ll intLeft = 0;
	FOR(intI, 1, arr[intN - 1].first + 5)
	{
		intLeft = intV;
		while (arr[intCur].first == intI)
		{
			intFirst += arr[intCur].second;
			intCur++;
		}

		if (intSecond > 0)
		{
			if (intLeft <= intSecond)
			{
				intSecond -= intLeft;
				intSum += intLeft;
				intLeft = 0;
			}
			else
			{
				intSum += intSecond;
				intLeft -= intSecond;
				intSecond = 0;
			}
		}
		
		if (intFirst > 0)
		{
			if (intLeft <= intFirst)
			{
				intFirst -= intLeft;
				intSum += intLeft;
				intLeft = 0;
			}
			else
			{
				intSum += intFirst;
				intLeft -= intFirst;
				intFirst = 0;
			}
		}

		intSecond = intFirst;
		intFirst = 0;
	}

	cout << intSum << endl;

	return 0;
}

//======================================================================================================================