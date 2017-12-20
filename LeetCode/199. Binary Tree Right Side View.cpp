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

//----------------------------------------------------------------------------------------------------------------------

struct TreeNode 
{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
	vector<int> ans;
	vector<int> rightSideView(TreeNode* root) 
	{
		solve(root, 0);
		return ans;
	}

	void solve(TreeNode* cur, ll level)
	{
		if (!cur) return;
		if (level >= ans.size())
		{
			ans.pb(cur->val);
		}
		else
		{
			ans[level] = cur->val;
		}

		solve(cur->left, level + 1);
		solve(cur->right, level + 1);
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	

	return 0;
}

//======================================================================================================================