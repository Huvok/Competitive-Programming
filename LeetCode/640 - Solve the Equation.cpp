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
class Solution 
{
public:
	string solveEquation(string equation) 
	{
		int x = 0, num = 0;
		vector<string> v;

		for (int intI = 0; intI < equation.length(); intI++)
		{
			for (int intJ = intI + 1; intJ < equation.length(); intJ++)
			{
				if (equation[intJ] == '-' ||
					equation[intJ] == '+' ||
					equation[intJ] == '=' ||
					intJ == equation.length() - 1)
				{
					if (intJ == equation.length() - 1)
					{
						v.push_back(equation.substr(intI, intJ - intI + 1));
						intI = intJ - 1;
						
					}
					else
					{
						v.push_back(equation.substr(intI, intJ - intI));
						intI = intJ - 1;
					}

					if (equation[intJ] == '=')
					{
						v.push_back(equation.substr(intI + 1, 1));
						intI++;

						if (intI == equation.length() - 2)
						{
							v.push_back(equation.substr(intI + 1, 1));
						}
						break;
					}

					break;
				}
			}
		}

		bool eq = false;
		for (int intI = 0; intI < v.size(); intI++)
		{
			if (eq)
			{
				if (v[intI][v[intI].size() - 1] == 'x')
				{
					if (v[intI][0] == '-')
					{
						if (v[intI].size() > 2)
						{
							x += atoi(v[intI].substr(1, v[intI].size() - 2).c_str());
						}
						else
						{
							x++;
						}
					}
					else
					{
						if (v[intI][0] == '+')
						{
							if (v[intI].size() > 2)
							{
								x -= atoi(v[intI].substr(1, v[intI].size() - 2).c_str());
							}
							else
							{
								x--;
							}
						}
						else
						{
							if (v[intI].size() > 1)
							{
								x -= atoi(v[intI].substr(0, v[intI].size() - 1).c_str());
							}
							else
							{
								x--;
							}
						}
					}
				}
				else
				{
					if (v[intI][0] == '-')
					{
						num -= atoi(v[intI].substr(1, v[intI].size() - 1).c_str());
					}
					else
					{
						if (v[intI][0] == '+')
						{
							num += atoi(v[intI].substr(1, v[intI].size() - 1).c_str());
						}
						else
						{
							num += atoi(v[intI].c_str());
						}
					}
				}
			}
			else if (v[intI][0] == '=')
			{
				eq = true;
			}
			else
			{
				if (v[intI][v[intI].size() - 1] == 'x')
				{
					if (v[intI][0] == '-')
					{
						if (v[intI].size() > 2)
						{
							x -= atoi(v[intI].substr(1, v[intI].size() - 1).c_str());
						}
						else
						{
							x--;
						}
					}
					else
					{
						if (v[intI][0] == '+')
						{
							if (v[intI].size() > 2)
							{
								x += atoi(v[intI].substr(1, v[intI].size() - 1).c_str());
							}
							else
							{
								x++;
							}
						}
						else
						{
							if (v[intI].size() > 1)
							{
								x += atoi(v[intI].substr(0, v[intI].size() - 1).c_str());
							}
							else
							{
								x++;
							}
						}
					}
				}
				else
				{
					if (v[intI][0] == '-')
					{
						num += atoi(v[intI].substr(1, v[intI].size() - 1).c_str());
					}
					else
					{
						if (v[intI][0] == '+')
						{
							num -= atoi(v[intI].substr(1, v[intI].size() - 1).c_str());
						}
						else
						{
							num -= atoi(v[intI].c_str());
						}
					}
				}
			}
		}

		if (x > 0)
		{
			return "x=" + to_string(num / x);
		}
		else if (x < 0)
		{
			return "x=" + to_string(num / x);
		}
		else if (x == 0 &&
			num == 0)
		{
			return "Infinite solutions";
		}
		else
		{
			return "No solution";
		}
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	Solution s;
	cout << s.solveEquation("x=x+2");

	return 0;
}
//======================================================================================================================