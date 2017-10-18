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
class Solution 
{
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
	{
		ll m = nums1.size();
		ll n = nums2.size();
		if (m > n) return findMedianSortedArrays(nums2, nums1);

		ll l = 0, h = m, half = (n + m + 1) / 2;
		while (l <= h)
		{
			ll i = (l + h) >> 1;
			ll j = half - i;

			if (i < h &&
				nums2[j - 1] > nums1[i]) l = i + 1;
			else if (i > l &&
				nums1[i - 1] > nums2[j]) h = i - 1;
			else
			{
				ll maxLeft = 0, minRight = 0;
				if (!i) maxLeft = nums2[j - 1];
				else if (!j) maxLeft = nums1[i - 1];
				else maxLeft = max(nums1[i - 1], nums2[j - 1]);

				if ((m + n) % 2 == 1) return maxLeft;

				if (i == m) minRight = nums2[j];
				else if (j == n) minRight = nums1[i];
				else minRight = min(nums1[i], nums2[j]);

				return (maxLeft + minRight) / 2.0;
			}
		}

		return 0.0;
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{

	return 0;
}
//======================================================================================================================