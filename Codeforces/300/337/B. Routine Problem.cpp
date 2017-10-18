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
ll gcd(ll a, ll b) 
{
	if (b) return gcd(b, a % b);
	return a;
}

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	double a, b, c, d;
	ll p, q;
	cin >> a >> b >> c >> d;
	if (abs((a / b) - (c / d)) < .00000000005)
	{
		cout << "0/1" << endl;
		return 0;
	}
	else if (a / b < c / d)
	{
		p = (b * c - a * d);
		q = (b * c);
	}
	else if (a / b > c / d)
	{
		p = (a * d - b * c);
		q = (a * d);
	}

	ll intGCD = gcd(p, q);
	p /= intGCD;
	q /= intGCD;

	cout << p << "/" << q << endl;
	
	return 0;
}

//======================================================================================================================