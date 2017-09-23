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
	 ListNode* rotateRight(ListNode* head, int k)
	 {
		 if (head == NULL) return head;
		 int intLen = 1;
		 ListNode* temp = head;

		 while (temp->next)
		 {
			 intLen++;
			 temp = temp->next;
		 }

		 k %= intLen;
		 if (!k) return head;
		 temp->next = head;
		 for (int intI = 0; intI < intLen - k; intI++) temp = temp->next;

		 ListNode* newHead = temp->next;
		 temp->next = NULL;

		 return newHead;
	 }
 };

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	Solution s;

	ListNode head(1);
	ListNode tail(2);
	head.next = &tail;
	cout << s.rotateRight(&head, 1);
	return 0;
}
//======================================================================================================================