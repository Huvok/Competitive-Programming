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
vi numbers;

void prec(string s)
{
	if (s.length() > 10) return;

	FOR(intI, 0, 10)
	{


		s[0] = intI + '0';
		s[s.length() - 1] = intI + '0';

		if (s[0] != '0')
		{
			numbers.pb(atoll(s.c_str()));
		}

		prec("1" + s + "1");
	}
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll intK, intP;
	scanf("%lld %lld", &intK, &intP);

	prec("00");

	sort(all(numbers));

	ll intSum = 0;
	if (intK == 100000)
	{
		intK--;
		intSum = 100000000001 % intP;
	}
	FOR(intI, 0, intK)
	{
		intSum += (numbers[intI] % intP);
		intSum %= intP;
	}

	printf("%lld\n", intSum);
	fflush(stdout);

	return 0;
}

//======================================================================================================================