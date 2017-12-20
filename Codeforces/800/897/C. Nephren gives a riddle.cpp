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

typedef unsigned long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

using namespace std;

//----------------------------------------------------------------------------------------------------------------------
ll dp[100005];
string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string f1 = "What are you doing while sending \"\"? Are you busy? Will you send \"\"?";

ii queries[10];

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll intQ, intN, intK;

	scanf("%lld", &intQ);

	ll intMax = 0;
	FOR(intI, 0, intQ)
	{
		scanf("%lld %lld", &intN, &intK);
		intMax = max(intMax, intN);
		queries[intI] = mp(intN, intK);
	}

	dp[0] = f0.length();

	FOR(intI, 1, intMax + 1)
	{
		dp[intI] = f1.length() + dp[intI - 1] * 2;
	}

	ll groups[5];
	groups[0] = 34;
	groups[2] = 32;
	groups[4] = 2;
	string ans = "";
	FOR(intI, 0, intQ)
	{
		intN = queries[intI].first; intK = queries[intI].second;

		if (intK <= dp[intN])
		{
			while (true)
			{
				if (intN == 0)
				{
					ans += f0[intK - 1];
					break;
				}

				groups[1] = groups[3] = dp[intN - 1];

				if (intK <= groups[0])
				{
					ans += f1[intK - 1];
					break;
				}
				else if (intK <= groups[1] + groups[0])
				{
					intK -= groups[0];
					intN--;
				}
				else if (intK <= groups[2] + groups[1] + groups[0])
				{
					intK -= groups[1];
					ans += f1[intK - 1];
					break;
				}
				else if (intK <= groups[3] + groups[2] + groups[1] + groups[0])
				{
					intK -= groups[0]; intK -= groups[1]; intK -= groups[2];
					intN--;
				}
				else
				{
					intK -= groups[1];
					intK -= groups[3];
					ans += f1[intK - 1];
					break;
				}
			}
		}
		else
		{
			ans += ".";
		}
	}

	printf("%s\n", ans.c_str());
	fflush(stdout);

	return 0;
}

//======================================================================================================================