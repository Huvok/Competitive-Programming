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
		double numMin, numMax;
		for (int intI = 0; intI < nums.size(); intI++)
		{
			if (!intI)
			{
				numMin = nums[intI];
				numMax = nums[intI];
			}
			else
			{
				numMin = min(numMin, nums[intI] * 1.0);
				numMax = max(numMax, nums[intI] * 1.0);
			}
		}

		double numPrevGuess = numMax;
		double error = 9000000000, numMid;
		while (error > .00001)
		{
			numMid = (numMax + numMin) * .5;
			if (boolGuess(numMid, nums, k))
			{
				numMin = numMid;
			}
			else
			{
				numMax = numMid;
			}

			error = abs(numPrevGuess - numMid);
			numPrevGuess = numMid;
		}

		return numMid;
	}

	bool boolGuess(double numMid, vector<int> nums, int k)
	{
		double numSum = 0, numPrevSum = 0, numMinSum = 0;
		for (int intI = 0; intI < k; intI++)
		{
			numSum += nums[intI] - numMid;
		}

		if (numSum >= 0)
		{
			return true;
		}

		for (int intI = k; intI < nums.size(); intI++) {
			numSum += nums[intI] - numMid;
			numPrevSum += nums[intI - k] - numMid;
			numMinSum = min(numPrevSum, numMinSum);
			if (numSum >= numMinSum)
			{
				return true;
			}
		}

		return false;
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{

	return 0;
}
//======================================================================================================================