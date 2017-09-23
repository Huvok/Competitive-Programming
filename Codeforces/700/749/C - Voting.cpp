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

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN;
	queue<ll> qd, qr;

	cin >> intN;
	char n;
	FOR(intI, 0, intN)
	{
		cin >> n;
		if (n == 'D') qd.push(intI);
		else qr.push(intI);
	}

	while (!qd.empty() && !qr.empty())
	{
		if (qd.front() < qr.front())
		{
			ll intNext = qd.front();
			qd.pop();
			qd.push(intNext + intN);
			qr.pop();
		}
		else
		{
			ll intNext = qr.front();
			qr.pop();
			qr.push(intNext + intN);
			qd.pop();
		}
	}

	if (!qd.empty()) cout << "D" << endl;
	else cout << "R" << endl;

	return 0;
}
//======================================================================================================================