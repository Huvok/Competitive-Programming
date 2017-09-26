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
#include <climits>
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
struct Point {
	ll x, y;
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	Point p1, p2, p3;
	cin >> p1.x >> p1.y;
	cin >> p2.x >> p2.y;
	cin >> p3.x >> p3.y;

	cout << 3 << endl;
	cout << p1.x + p2.x - p3.x << " " << p1.y + p2.y - p3.y << endl;
	cout << p1.x + p3.x - p2.x << " " << p1.y + p3.y - p2.y << endl;
	cout << p2.x + p3.x - p1.x << " " << p2.y + p3.y - p1.y << endl;

	return 0;
}
//======================================================================================================================