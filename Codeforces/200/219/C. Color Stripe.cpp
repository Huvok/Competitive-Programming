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
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

using namespace std;

//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll n, k;
	cin >> n >> k;
	string str;
	cin >> str;

	ll ans = 0;

	if (k == 2)
	{
		ll s1 = 0, s2 = 0;
		FOR(i, 0, str.length())
		{
			if (i % 2 == 0)
			{
				if (str[i] != 'A')
					s1++;
				if (str[i] != 'B')
					s2++;
			}
			else
			{
				if (str[i] != 'B')
					s1++;
				if (str[i] != 'A')
					s2++;
			}
		}

		ans = min(s1, s2);
		if (s1 < s2)
		{
			FOR(i, 0, str.length())
			{
				if (i % 2 == 0)
				{
					str[i] = 'A';
				}
				else
					str[i] = 'B';
			}
		}
		else
		{
			FOR(i, 0, str.length())
			{
				if (i % 2 == 0)
				{
					str[i] = 'B';
				}
				else
					str[i] = 'A';
			}
		}
	}
	else
	{
		k--;
		FOR(i, 1, str.length())
		{
			if (str[i] == str[i - 1])
			{
				ans++;
				if (str[i] - 'A' == k)
				{
					str[i]--;
					if (i < str.length() - 1)
						if (str[i] == str[i + 1])
							str[i]--;
				}
				else
				{
					str[i]++;
					if (i < str.length() - 1)
						if (str[i] == str[i + 1])
						{
							if (str[i] - 'A' == k)
							{
								str[i] = 'A';
							}
							else
							{
								str[i]++;
							}
						}
				}
			}
		}
	}

	cout << ans << endl;
	cout << str << endl;

	return 0;
}

//====================================================================================================================== 