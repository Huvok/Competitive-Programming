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

//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
using namespace std;

double getAverage(vector<int> arr)
{
	int intSum = 0;

	for (int intI = 0; intI < arr.size(); intI++)
	{
		intSum += arr[intI];
	}

	double average = (intSum * 1.0) / arr.size();
	return average;
}

int main()
{

	int intN, intK, intAux, intCount = 0;
	cin >> intN >> intK;

	vector<int> arr;

	for (int intI = 0; intI < intN; intI++)
	{
		cin >> intAux;
		arr.push_back(intAux);
	}

	while (getAverage(arr) < (intK - .5))
	{
		arr.push_back(intK);
		intCount++;
	}

	cout << intCount << endl;

	return 0;
}
//======================================================================================================================