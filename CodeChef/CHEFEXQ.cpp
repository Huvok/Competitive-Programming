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
struct bucket
{
	ll leader;
	ll arr[320];
	int app[1048585];
};

bucket decomp[320];

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll intN, intQ;

	scanf("%lld %lld", &intN, &intQ);
	ll step = (sqrt(intN));
	ll curStep = 0, cur = 0;
	ll curXor = 0;
	FOR(intI, 0, intN)
	{
		scanf("%lld", &decomp[curStep].arr[cur]);
		curXor ^= decomp[curStep].arr[cur];
		cur++;
		decomp[curStep].app[curXor]++;
		if (cur >= step)
		{
			decomp[curStep].leader = curXor;
			cur = 0;
			curStep++;
			curXor = 0;
		}
	}

	decomp[curStep].leader = curXor;
	cur = 0;
	curStep++;
	curXor = 0;
	FOR(intI, 0, intQ)
	{
		ll a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);

		if (a == 1)
		{
			ll stepNum = (b - 1) / step;
			ll curXor = 0;
			FOR(i, 0, step)
			{
				if (stepNum == step)
				{
					if (i >= intN % step)
						break;
				}
				curXor ^= decomp[stepNum].arr[i];
				decomp[stepNum].app[curXor] = 0;
			}

			decomp[stepNum].arr[(b - 1) % step] = c;

			curXor = 0;
			FOR(i, 0, step)
			{
				if (stepNum == step)
				{
					if (i >= intN % step)
						break;
				}
				curXor ^= decomp[stepNum].arr[i];
				decomp[stepNum].app[curXor]++;
			}

			decomp[stepNum].leader = curXor;
		}
		else
		{
			ll count = 0;
			ll cur = 0;
			FOR(i, 0, (b / step))
			{
				count += decomp[i].app[cur ^ c];
				cur ^= decomp[i].leader;
			}

			FOR(i, 0, b % step)
			{
				cur ^= decomp[b / step].arr[i];
				if (cur == c) count++;
			}

			printf("%lld\n", count);
		}
	}
	return 0;
}

//======================================================================================================================