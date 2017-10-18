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
struct Interval 
{
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};

class Solution 
{
public:
	vector<Interval> merge(vector<Interval>& intervals) 
	{
		vector<Interval> ans;
		if (intervals.size() == 0) return ans;
		sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return a.start < b.start; });
		ll intStart = intervals[0].start;
		ll intEnd = intervals[0].end;
		FOR(intI, 1, intervals.size())
		{
			if (intervals[intI].start > intEnd)
			{
				Interval i(intStart, intEnd);
				ans.pb(i);
				intStart = intervals[intI].start;
				intEnd = intervals[intI].end;
			}
			else
			{
				intEnd = max(intEnd, (ll)intervals[intI].end);
			}
		}

		Interval i(intStart, intEnd);
		ans.pb(i);
		return ans;
	}
};

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	

	return 0;
}
//======================================================================================================================