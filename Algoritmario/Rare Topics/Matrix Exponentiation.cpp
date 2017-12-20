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
#define MAX_N 2
#define MOD 1000000007
struct Matrix
{
	ll mat[MAX_N][MAX_N];
};

Matrix matMul(Matrix a, Matrix b)
{
	Matrix ans;
	FOR(i, 0, MAX_N)
	{
		FOR(j, 0, MAX_N)
		{
			ans.mat[i][j] = 0;
			FOR(k, 0, MAX_N)
			{
				ans.mat[i][j] += (a.mat[i][k] * b.mat[k][j] % MOD);
				ans.mat[i][j] %= MOD;
			}
		}
	}

	return ans;
}

Matrix matPow(Matrix base, ll p)
{
	Matrix ans;
	ans.mat[0][0] = 1;
	ans.mat[0][1] = 0;
	ans.mat[1][0] = 0;
	ans.mat[1][1] = 0;

	while (p)
	{
		if (p & 1)
			ans = matMul(ans, base);
		base = matMul(base, base);
		p >>= 1;
	}

	return ans;
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	ll intN;
	cin >> intN;

	Matrix mat;
	mat.mat[0][0] = 0;
	mat.mat[0][1] = 3;
	mat.mat[1][0] = 1;
	mat.mat[1][1] = 2;

	Matrix ans = matPow(mat, intN);

	cout << ans.mat[0][0] << endl;

	return 0;
}

//======================================================================================================================