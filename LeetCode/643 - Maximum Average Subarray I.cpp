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

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//======================================================================================================================
class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k)
	{
		double numChamp = -50000000.00;
		double cur = 0;

		for (int intI = 0; intI < k; intI++)
		{
			cur += nums[intI];
		}

		for (int intI = 0; intI < nums.size() - k + 1; intI++)
		{
			numChamp = max(numChamp, cur * 1.0 / k);
			cur -= nums[intI];
			cur += nums[intI + k];
		}

		return numChamp;
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{

	return 0;
}
//======================================================================================================================