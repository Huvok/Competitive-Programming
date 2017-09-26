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
#include <climits>
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
struct ListNode 
{
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
		ListNode* n1 = l1, * n2 = l2;
		ListNode* head = NULL;
		ListNode* prev = NULL;
		ll intCarry = 0;
		while (l2 || l1)
		{
			ll intVal = 0;
			intVal += l1 ? l1->val : 0;
			intVal += l2 ? l2->val : 0;
			intVal += intCarry;
			ListNode* node = new ListNode(intVal % 10);
			if (!head) head = node;
			if (prev) prev->next = node;
			prev = node;
			intCarry = intVal > 9 ? 1 : 0;
			if (l2) l2 = l2->next;
			if (l1) l1 = l1->next;
		}

		if (intCarry)
		{
			ListNode* node = new ListNode(1);
			prev->next = node;
		}

		return head;
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ListNode l1(5), l2(5), l3(3), l4(5), l5(6), l6(4);
	l1.next = &l2;
	l2.next = &l3;
	l4.next = &l5;
	l5.next = &l6;

	Solution sol;
	sol.addTwoNumbers(&l1, &l4);

	return 0;
}
//======================================================================================================================