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

typedef int ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

using namespace std;

//----------------------------------------------------------------------------------------------------------------------
bool suffix(string a, string b)
{
	if (a.length() > b.length())
		swap(a, b);

	ll idx = 0;
	RFOR(i, a.length() - 1, 0)
	{
		if (a[i] != b[b.length() - 1 - idx])
			return false;
		idx++;
	}

	return true;
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll n;
	cin >> n;
	cin.ignore();
	string str;
	vector<string> ans;
	bool valid[200];
	string phones[200];
	unordered_map<string, vector<string>> m;
	
	FOR(i, 0, n)
	{
		string name;
		cin >> name;
		ll q;
		cin >> q;

		string strNext;
		FOR(j, 0, q)
		{
			cin >> strNext;
			m[name].pb(strNext);
		}
	}

	for (auto it : m)
	{
		memset(valid, true, sizeof(valid));
		FOR(i, 0, it.second.size())
		{
			FOR(j, i, it.second.size())
			{
				if (i != j &&
					suffix(it.second[i], it.second[j]) &&
					valid[i])
				{
					if (it.second[i].length() <= it.second[j].length())
					{
						valid[i] = false;
					}
					else
					{
						valid[j] = false;
					}
				}
			}
		}

		ll valids = 0;
		FOR(j, 0, it.second.size())
		{
			if (valid[j])
				valids++;
		}

		string fin = it.first + " " + to_string(valids);
		FOR(i, 0, it.second.size())
		{
			if (valid[i])
			{
				fin += " " + it.second[i];
			}
		}

		ans.pb(fin);
	}

	cout << ans.size() << endl;
	FOR(i, 0, ans.size())
	{
		cout << ans[i] << endl;
	}

	return 0;
}

//====================================================================================================================== 