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
struct model
{
	ll intL, intH;
	string str;
};
//----------------------------------------------------------------------------------------------------------------------
int main()
{
	ll intT;
	cin >> intT;
	vector<model> v;
	
	while (intT--)
	{
		v.clear();
		ll intN, intQ;
		cin >> intN;

		for (ll intI = 0; intI < intN; intI++)
		{
			model m;
			cin >> m.str >> m.intL >> m.intH;
			v.push_back(m);
		}

		cin >> intQ;
		
		string strChamp;
		for (ll intI = 0; intI < intQ; intI++)
		{
			ll intMatches = 0;
			ll intM;
			cin >> intM;
			for (ll intJ = 0; intJ < intN; intJ++)
			{
				if (v[intJ].intL <= intM &&
					v[intJ].intH >= intM)
				{
					intMatches++;
					strChamp = v[intJ].str;
				}

				if (intMatches > 1) break;
			}

			if (intMatches == 1)
			{
				cout << strChamp << endl;
			}
			else
			{
				cout << "UNDETERMINED" << endl;
			}
		}

		if (intT) cout << endl;
	}

	return 0;
}
//======================================================================================================================