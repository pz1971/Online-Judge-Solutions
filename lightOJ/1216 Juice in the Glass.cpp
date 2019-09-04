#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

const double pi = acos(-1.0);

int main(){

	int t;
	double r1, r2, h, p, dr, r3, H, v;

	scanf("%d", &t);

	for(int tc=1; tc<=t; tc++){
		scanf("%lf %lf %lf %lf", &r1, &r2, &h, &p);
		dr = (r1 - r2) / h;
		r3 = r2 + p * dr;
		H = r3 / dr;
		v = ( r3*r3*H - r2*r2*(H-p) ) * pi / 3.0;
		printf("Case %d: %.7lf\n", tc, v);
	}

	return 0;
}