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
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
	{
		//													//"Use the non-null node".
		if (!t1) return t2;
		if (!t2) return t1;

		//													//If we are here both are non-null.
		t1->val += t2->val;
		t1->left = mergeTrees(t1->left, t2->left);
		t1->right = mergeTrees(t1->right, t2->right);

		return t1;
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	TreeNode t1(1);
	TreeNode t2(3);
	TreeNode t3(2);
	TreeNode t4(5);

	TreeNode t5(2);
	TreeNode t6(1);
	TreeNode t7(3);
	TreeNode t8(4);
	TreeNode t9(7);

	t1.left = &t2;
	t1.right = &t3;
	t2.left = &t4;
	t5.left = &t6;
	t5.right = &t7;
	t6.right = &t8;
	t7.right = &t9;
	Solution s;
	TreeNode* hue = s.mergeTrees(&t1, &t5);
	return 0;
}
//======================================================================================================================