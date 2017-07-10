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
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution {
public:
	vector<double> v;
	vector<int> arr;
	vector<double> averageOfLevels(TreeNode* root)
	{
		solve(root, 0);

		for (int intI = 0; intI < v.size(); intI++)
		{
			v[intI] = v[intI] / arr[intI];
		}

		return v;
	}

	void solve(TreeNode* root, int level)
	{
		if (arr.size() <= level) arr.push_back(0);
		arr[level]++;
		if (v.size() <= level) v.push_back(0);
		v[level] += root->val;
		if (root->left != NULL) solve(root->left, level + 1);
		if (root->right != NULL) solve(root->right, level + 1);
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	

	return 0;
}
//======================================================================================================================