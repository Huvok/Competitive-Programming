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
typedef pair<int, int> ii;
typedef vector<ii> vii;

//======================================================================================================================
class NumArray 
{
public:
	vector<int> vSum;
	NumArray(vector<int> nums) 
	{
		vSum.assign(nums.size(), 0);

		for (ll intI = 0; intI < nums.size(); intI++)
		{
			if (!intI)
			{
				vSum[intI] = nums[intI];
			}
			else
			{
				vSum[intI] = nums[intI] + vSum[intI - 1];
			}
		}
	}

	int sumRange(int i, int j) 
	{
		if (!i)
		{
			return vSum[j];
		}
		else
		{
			return vSum[j] - vSum[i - 1];
		}
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	

	return 0;
}
//======================================================================================================================