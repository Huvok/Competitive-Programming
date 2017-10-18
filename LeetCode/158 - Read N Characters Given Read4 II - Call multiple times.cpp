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

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
queue<int> left;
int read(char *buf, int n) 
{
	int len = 0;
	int c;
	while (left.size() > 0) {
		buf[len++] = left.front();
		left.pop();
		if (len == n) return len;
	}

	while (len < n) {
		c = read4(buf + len);
		len += c;
		if (c < 4) break;
	}

	for (int i = n; i<len; i++) {
		left.push(buf[i]);
	}
	int e = min(len, n);
	buf[e] = '\0';
	return e;
}
//----------------------------------------------------------------------------------------------------------------------

int main()
{

	return 0;
}
//======================================================================================================================