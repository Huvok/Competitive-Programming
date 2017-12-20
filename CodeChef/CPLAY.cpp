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
#include <limits.h>

using namespace std;

//															//AUTHOR: Hugo Garcia
//															//PURPOSE: Competitive programming template

//======================================================================================================================

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define RFOR(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define pb push_back
#define mp make_pair
#define lld I64d
#define all(a) (a).begin(), (a).end()
#define ifile(a) freopen((a), "r", stdin)
#define ofile(a) freopen((a), "w", stdout)
#define sync ios_base::sync_with_stdio(false)

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

using namespace std;

//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	string s;
	while (cin >> s)
	{
		ll i = 0;
		ll a = 0, b = 0;
		ll sa = 0, sb = 0;
		while (true)
		{
			if (s[i] == '1')
			{
				if (i & 1)
				{
					b++;
				}
				else
				{
					a++;
				}
			}

			if (i & 1)
			{
				sb++;
			}
			else
			{
				sa++;
			}

			if (i >= 20)
			{
				cout << "TIE" << endl;
				break;
			}

			if (i >= 10 &&
				i % 2 == 1 &&
				a != b)
			{
				if (a > b)
				{
					cout << "TEAM-A " << i + 1 << endl;
					break;
				}
				else
				{
					cout << "TEAM-B " << i + 1 << endl;
					break;
				}
			}
			else if (i < 10)
			{
				if (5 - sa < (b - a))
				{
					cout << "TEAM-B " << i + 1 << endl;
					break;
				}
				else if (5 - sb < (a - b))
				{
					cout << "TEAM-A " << i + 1 << endl;
					break;
				}
			}

			i++;
		}
	}

	return 0;
}

//======================================================================================================================