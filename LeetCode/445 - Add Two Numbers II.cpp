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
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
		stack<ll> s1, s2;

		while (l1)
		{
			s1.push(l1->val);
			l1 = l1->next;
		}

		while (l2)
		{
			s2.push(l2->val);
			l2 = l2->next;
		}

		ll intVal = 0;

		ListNode* head = NULL;
		ll intCarry = 0;
		while (!s1.empty() || !s2.empty())
		{
			if (!s1.empty())
			{
				intVal += s1.top();
				s1.pop();
			}

			if (!s2.empty())
			{
				intVal += s2.top();
				s2.pop();
			}

			ListNode* node = new ListNode((intVal + intCarry) % 10);
			if (intVal + intCarry >= 10) intCarry = 1;
			else intCarry = 0;
			if (head) node->next = head;
			head = node;
			intVal = 0;
		}

		if (intCarry)
		{
			ListNode* node = new ListNode(1);
			if (head) node->next = head;
			head = node;
		}

		return head;
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	Solution sol;
	ListNode n1(1);
	ListNode m1(9), m2(9);

	m1.next = &m2;

	sol.addTwoNumbers(&n1, &m1);

	return 0;
}
//======================================================================================================================