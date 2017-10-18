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
class Solution
{
public:
	string alphabet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	unordered_map<string, string> m;
	string key = getRand();

	string getRand()
	{
		string s = "";
		for (int i = 0; i < 6; i++)
		{
			s += alphabet[rand() % (sizeof(alphabet) - 1)];
		}

		return s;
	}

	// Encodes a URL to a shortened URL.
	string encode(string longUrl)
	{
		while (m.find(key) != m.end())
		{
			key = getRand();
		}

		m.insert(make_pair(key, longUrl));

		return "http://tinyurl.com/" + key;
	}

	// Decodes a shortened URL to its original URL.
	string decode(string shortUrl)
	{
		return m[shortUrl.substr(19)];
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	

	return 0;
}
//======================================================================================================================