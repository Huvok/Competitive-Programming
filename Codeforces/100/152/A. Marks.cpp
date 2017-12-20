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
#include <limits.h>

using namespace std;

//															//AUTHOR: Hugo Garcia
//															//PURPOSE: Competitive programming template

//======================================================================================================================

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define RFOR(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define pb push_back
#define mp make_pair
#define lld I64d
#define all(a) (a).begin(), (a).end()
#define ifile(a) freopen((a), "r", stdin)
#define ofile(a) freopen((a), "w", stdout)
#define sync ios_base::sync_with_stdio(false)

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

using namespace std;

//----------------------------------------------------------------------------------------------------------------------
ll arr[505];
string arrS[505];

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll intN, intM;
	cin >> intN >> intM;
	memset(arr, 0, sizeof(arr));
	FOR(intI, 0, intN)
	{
		cin >> arrS[intI];
		FOR(intJ, 0, arrS[intI].length())
		{
			arr[intJ] = max((int)arr[intJ], arrS[intI][intJ] - '0');
		}
	}

	ll intCount = 0;
	FOR(intI, 0, intN)
	{
		FOR(intJ, 0, intM)
		{
			if (arrS[intI][intJ] - '0' >= arr[intJ])
			{
				intCount++;
				break;
			}
		}
	}

	cout << intCount << endl;

	return 0;
}

//======================================================================================================================