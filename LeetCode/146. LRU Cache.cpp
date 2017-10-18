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
#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define pb push_back
#define mp make_pair
#define lld I64d

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

//----------------------------------------------------------------------------------------------------------------------
class LRUCache
{
private:
	int intSize;
	list<int> lst;
	unordered_map<int, pair<int, list<int>::iterator>> m;
public:
	LRUCache(int capacity)
	{
		this->intSize = capacity;
	}

	int get(int key)
	{
		auto it = m.find(key);
		if (it == m.end()) return -1;
		enqueue(it);
		return it->second.first;
	}

	void put(int key, int value)
	{
		auto it = m.find(key);
		if (it == m.end())
		{
			while (m.size() >= intSize)
			{
				m.erase(lst.back());
				lst.pop_back();
			}

			lst.push_front(key);
		}
		else
		{
			enqueue(it);
		}


		m[key] = { value, lst.begin() };
	}

	void enqueue(unordered_map<int, pair<int, list<int>::iterator>>::iterator it)
	{
		int key = it->first;
		lst.erase(it->second.second);
		lst.push_front(key);
		it->second.second = lst.begin();
	}
};

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	
	return 0;
}
//======================================================================================================================