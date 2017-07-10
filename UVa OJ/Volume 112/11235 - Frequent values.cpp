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

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

//======================================================================================================================
class SegmentTree
{
private:
	vi st, A;
	ll n;

	ll left(ll p)
	{
		return p << 1;
	}

	ll right(ll p)
	{
		return (p << 1) + 1;
	}

	void build(ll p, ll L, ll R)
	{
		if (L == R)
		{
			st[p] = L;
		}
		else
		{
			build(left(p), L, (L + R) / 2);
			build(right(p), (L + R) / 2 + 1, R);
			ll p1 = st[left(p)], p2 = st[right(p)];
			st[p] = (A[p1] >= A[p2]) ? p1 : p2;
		}
	}

	ll rmq(ll p, ll L, ll R, ll i, ll j)
	{
		if (i > R || j < L) return -1;
		if (L >= i && R <= j) return st[p];

		ll p1 = rmq(left(p), L, (L + R) / 2, i, j);
		ll p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);

		if (p1 == -1) return p2;
		if (p2 == -1) return p1;
		return (A[p1] >= A[p2]) ? p1 : p2;
	}

public:
	SegmentTree(const vi &_A)
	{
		A = _A; n = (ll)A.size();
		st.assign(4 * n, 0);
		build(1, 0, n - 1);
	}

	ll rmq(ll i, ll j)
	{
		return rmq(1, 0, n - 1, i, j);
	}
};

ll L[100005], R[100005], arr[100005];
//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intN, intQ;
	vi v;
	while (true)
	{
		scanf("%lld", &intN);
		if (!intN) break;
		v.assign(intN, 0);
		scanf("%lld", &intQ);
		for (ll intI = 0; intI < intN; intI++)
		{
			scanf("%lld", &arr[intI]);
		}

		ll intCurrent, intCount = 0, intL, intR;
		for (ll intI = 0; intI < intN; intI++)
		{
			if (!intI)
			{
				intCurrent = arr[intI];
				intCount++;
				L[intI] = intI;
				intL = intI;
				intR = intI;
			}
			else if (arr[intI] == intCurrent)
			{
				intCount++;
				L[intI] = intL;
				intR = intI;
			}
			else
			{
				for (ll intJ = intI - intCount; intJ < intI; intJ++)
				{
					v[intJ] = intCount;
					R[intJ] = intR;
				}

				intL = intI;
				L[intI] = intL;
				intR = intI;
				R[intI] = intR;
				intCurrent = arr[intI];
				intCount = 1;
			}

			if (intI == intN - 1)
			{
				for (ll intJ = intI - intCount + 1; intJ <= intI; intJ++)
				{
					v[intJ] = intCount;
					R[intJ] = intR;
				}
			}
		}

		SegmentTree st = SegmentTree(v);

		ll i, j;
		for (ll intI = 0; intI < intQ; intI++)
		{
			scanf("%lld %lld", &i, &j);
			i--;
			j--;

			if (arr[i] == arr[j])
			{
				printf("%lld\n", j - i + 1);
			}
			else if ((i == 0 ||
				(i != 0 && arr[i] != arr[i - 1])) &&
				(j == intN - 1 ||
				(j != intN - 1 && arr[j] != arr[j + 1])))
			{
				printf("%lld\n", v[st.rmq(i, j)]);
			}
			else if (i != 0 &&
				arr[i] == arr[i - 1] &&
				(j == intN - 1 ||
				(j != intN - 1 && arr[j] != arr[j + 1])))
			{
				printf("%lld\n", max(R[i] - i + 1, v[st.rmq(R[i] + 1, j)]));
			}
			else if ((i == 0 ||
				(i != 0 && arr[i] != arr[i - 1])) &&
				(j != intN - 1 && arr[j] == arr[j + 1]))
			{
				printf("%lld\n", max(j - L[j] + 1, v[st.rmq(i, L[j] - 1)]));
			}
			else
			{
				ll aux = st.rmq(R[i] + 1, L[j] - 1);
				printf("%lld\n", max(j - L[j] + 1, 
					max(R[i] - i + 1, (j - i > 2 && aux != -1) ? v[aux] : -1)));
			}
		}
	}

	return 0;
}
//======================================================================================================================