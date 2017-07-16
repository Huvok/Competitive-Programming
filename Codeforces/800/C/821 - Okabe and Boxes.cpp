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

using namespace std;

//															//AUTHOR: Hugo Garcia
//															//PURPOSE: Competitive programming template

//======================================================================================================================

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

//======================================================================================================================

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intNumber, intCurrent = 1, intAnswer = 0;
	string str;
	cin >> intN;
	stack<int> s;
	for (ll intI = 0; intI < intN * 2; intI++)
	{
		cin >> str;

		if (str == "add")
		{
			cin >> intNumber;
			s.push(intNumber);
		}
		else
		{
			if (!s.empty())
			{
				if (s.top() == intCurrent)
				{
					s.pop();
				}
				else
				{
					intAnswer++;
					while (!s.empty())
					{
						s.pop();
					}
				}
			}

			intCurrent++;
		}
	}

	cout << intAnswer << endl;

	return 0;
}
//======================================================================================================================