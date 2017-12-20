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
ll arr[200005];
set<ii> lens, segments;
ll n;

void segmentate()
{
	ll count = 0;
	ll start;
	ll cur;
	FOR(i, 0, n)
	{
		if (!i)
		{
			start = 0;
			cur = arr[i];
			count++;
		}
		else
		{
			if (arr[i] == arr[i - 1])
			{
				count++;
			}
			else
			{
				lens.insert(mp(-count, start));
				segments.insert(mp(start, count));
				start = i;
				cur = arr[i];
				count = 1;
			}
		}
	}

	lens.insert(mp(-count, start));
	segments.insert(mp(start, count));
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	scanf("%lld", &n);
	FOR(i, 0, n)
	{
		scanf("%lld", &arr[i]);
	}

	segmentate();
	ll ans = 0;
	while (!lens.empty())
	{
		ans++;
		ii cur = *lens.begin();
		auto it = segments.find({ cur.second, -cur.first });
		
		if (it != segments.begin() &&
			it != --segments.end())
		{
			it--;
			auto left = *it;
			it++; it++;
			auto right = *it;
			if (arr[left.first] == arr[right.first])
			{
				lens.erase({ -left.second, left.first });
				lens.erase({ -right.second, right.first });
				segments.erase(left);
				segments.erase(right);
				left.second += right.second;
				lens.insert({ -left.second, left.first });
				segments.insert(left);
			}
		}
		
		auto beg = *lens.begin();
		segments.erase({ beg.second, -beg.first });
		lens.erase(lens.begin());
	}

	printf("%lld\n", ans);
	return 0;
}

//====================================================================================================================== 