#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int main(){

	int t;
	double v1, v2, v3, a1, a2, t1, t2, d, d2;
	
	scanf("%d", &t);
	for(int tc=1; tc<=t; tc++){
		scanf("%lf %lf %lf %lf %lf", &v1, &v2, &v3, &a1, &a2);

		t1 = v1/a1;
		t2 = v2/a2;

		d = v1*t1 - .5*a1*t1*t1 + v2*t2 - .5*a2*t2*t2;
		d2 = max(t1, t2) * v3;

		printf("Case %d: %.8lf %.8lf\n", tc, d, d2);
	}

	return 0;
}