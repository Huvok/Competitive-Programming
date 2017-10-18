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
struct Point
{
	double x, y;
	Point(double x = 0, double y = 0) : x(x), y(y) {}
};

double hmax;
double D, L;
const double eps = 1e-8;

typedef Point Vector;

Vector operator + (Vector A, Vector B)
{
	return Vector(A.x + B.x, A.y + B.y);
}

Vector operator - (Point A, Point B)
{
	return Vector(A.x - B.x, A.y - B.y);
}

 Vector operator * (Vector A, double p)
{
	return Vector(A.x*p, A.y*p);
}

Vector operator / (Vector A, double p)
{
	return Vector(A.x / p, A.y / p);
}

 double Cross(Vector A, Vector B)
{
	return A.x*B.y - B.x*A.y;
}

 double PArea(Point *p, int n)
 {
	double area = 0;
	for (int i = 0; i<n; i++)
	{
		area += Cross(p[i], p[(i + 1) % n]);
	}
	return fabs(area / 2);
}

 Point GetLineIntersection(Point P, Vector v, Point Q, Vector w)
{
	Vector u = P - Q;
	return P + v*Cross(w, u) / Cross(v, w);
}

 Point read_point(Point &P)
{
	scanf("%lf%lf", &P.x, &P.y);
	hmax = max(hmax, P.y);
	return P;
}

//----------------------------------------------------------------------------------------------------------------------

int main()
{
	Point po[105], Q[105];
	int T, n, q, i;

	while (scanf("%d", &n) != EOF)
	{
		scanf("%lf%lf", &D, &L);
		hmax = 0;
		for (i = 0; i < n; i++)
		{
			read_point(po[i]);
		}

		double d = 0, h = hmax;

		while (h - d > eps)
		{
			q = 0;
			int per = n - 1;
			double m = (d + h) / 2;
			Point M(0, m);
			Vector w(1, 0);
			for (int i = 0; i < n; i++)
			{
				if ((m - po[i].y) * (m - po[per].y) < eps)
				{
					Vector PP = po[i] - po[per];
					Q[q++] = GetLineIntersection(po[per], PP, M, w);
				}

				if ((m - po[i].y) > eps)
				{
					Q[q++] = po[i];
				}

				per = i;
			}

			double area = PArea(Q, q);

			if (L * 1000 - area * D > eps)
				d = m;
			else
				h = m;
		}

		printf("%.2f\n", d);
	}

	return 0;
}
//======================================================================================================================