#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

const double pi = acos(-1.0);

int main(){

	int t;
	double Ox, Oy, Ax, Ay, Bx, By, theta, OA, AC, arc;

	scanf("%d", &t);
	for(int tc=1; tc<=t; tc++){
		scanf("%lf %lf %lf %lf %lf %lf", &Ox, &Oy, &Ax, &Ay, &Bx, &By);
		OA = sqrt((Ox - Ax)*(Ox - Ax) + (Oy - Ay)*(Oy - Ay));
		AC = sqrt((Ax - Bx)*(Ax - Bx) + (Ay - By)*(Ay - By)) / 2.0;
		theta = asin(AC / OA) * 2.0;
		arc = OA * theta;
		printf("Case %d: %.7lf\n", tc, arc);
	}

	return 0;
}