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
	int hIndex(vector<int>& citations)
	{
		vi v(citations.size() + 1, 0);
		FOR(intI, 0, citations.size())
		{
			v[min(citations[intI], (int)citations.size())]++;
		}


		ll intH = citations.size();
		for (ll intSum = v[citations.size()]; intH > intSum; intSum += v[intH])
		{
			intH--;
		}

		return intH;
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	return 0;
}
//======================================================================================================================