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
class MinStack 
{
private:
	stack<ll> s1, s2;
public:
	void push(int x) 
	{
		s1.push(x);
		if (s2.empty() ||
			x <= s2.top())
		{
			s2.push(x);
		}
	}

	void pop()
	{
		if (s1.top() == getMin())
		{
			s2.pop();
		}

		s1.pop();
	}

	int top() 
	{
		return s1.top();
	}

	int getMin() 
	{
		if (!s2.empty()) return s2.top();
		else return 0;
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{


	return 0;
}
//======================================================================================================================