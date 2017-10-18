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
class Solution 
{
public:
	TreeNode* upsideDownBinaryTree(TreeNode* root) 
	{
		if (root == NULL || root->left == NULL) return root;

		TreeNode* newRoot = upsideDownBinaryTree(root->left);
		root->left->left = root->right;
		root->left->right = root;
		root->left = NULL;
		root->right = NULL;
		return newRoot;
	}
};

//----------------------------------------------------------------------------------------------------------------------

int main()
{

	return 0;
}
//======================================================================================================================