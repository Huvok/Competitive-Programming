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
class Solution
{
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c)
	{
		if (nums.size() * nums[0].size() != r * c) return nums;
		vector<vector<int>> v(r, vector<int>(c));
		ll intCount = 0;
		FOR(i, 0, nums.size())
		{
			FOR(j, 0, nums[0].size())
			{
				v[intCount / c][intCount % c] = nums[i][j];
				intCount++;
			}
		}

		return v;
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{

	return 0;
}
//======================================================================================================================