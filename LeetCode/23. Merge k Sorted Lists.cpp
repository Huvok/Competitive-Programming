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
#define lld I64d

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------
int main()
{
	Solution sol;
	ListNode* a = new ListNode(1), *b = new ListNode(2), *c = new ListNode(3), *a1 = new ListNode(4), *b1 = new ListNode(5),
		*a2 = new ListNode(6), *b3 = new ListNode(7);
	vector<ListNode*> v;
	a->next = b;
	b->next = c;
	a1->next = b1;
	b1->next = a2;
	a2->next = b3;
	v.pb(a);
	v.pb(a1);
	sol.mergeKLists(v);
	return 0;
}
//======================================================================================================================