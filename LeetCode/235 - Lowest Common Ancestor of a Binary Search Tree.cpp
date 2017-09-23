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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
	{
		if (!root) return NULL;
		if (!p || !q) return NULL;
		if (p->val > root->val && q->val > root->val)
		{
			return lowestCommonAncestor(root->right, p, q);
		}
		else if (p->val < root->val && q->val < root->val)
		{
			return lowestCommonAncestor(root->left, p, q);
		}
		else
		{
			return root;
		}
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{


	return 0;
}
//======================================================================================================================