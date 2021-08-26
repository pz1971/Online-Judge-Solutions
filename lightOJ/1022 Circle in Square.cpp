#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int main(){

	int t;
	double r;
	const double pi = acos(-1.0);

	scanf("%d", &t);

	for(int tc=1; tc<=t; tc++){
		scanf("%lf", &r);
		printf("Case %d: %.2lf\n", tc, (r+r)*(r+r) - pi*r*r);
	}

	return 0;
}