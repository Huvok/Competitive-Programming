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
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		int intCur = m + n - 1;
		m--;
		n--;

		while (n >= 0 && m >= 0)
		{
			if (nums1[m] >= nums2[n])
			{
				nums1[intCur] = nums1[m];
				m--;
			}
			else
			{
				nums1[intCur] = nums2[n];
				n--;
			}

			intCur--;
		}

		while (n >= 0)
		{
			nums1[intCur] = nums2[n];
			intCur--;
			n--;
		}

	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{


	return 0;
}
//======================================================================================================================