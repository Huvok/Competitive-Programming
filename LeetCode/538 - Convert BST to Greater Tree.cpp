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

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int intSum;
	TreeNode* convertBST(TreeNode* root)
	{
		intSum = 0;
		solve(root);
		return root;
	}

	void solve(TreeNode* node)
	{
		if (node == NULL) return;
		solve(node->right);
		int intPrevVal = node->val;
		node->val += intSum;
		intSum += intPrevVal;
		solve(node->left);
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{
		return 0;
}
//======================================================================================================================