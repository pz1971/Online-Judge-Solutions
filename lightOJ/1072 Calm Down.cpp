#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

const double pi = acos(-1.0);

int main(){

	int t;
	double R, n;
	scanf("%d", &t);

	for(int tc=1; tc<=t; tc++){
		scanf("%lf %lf", &R, &n);
		printf("Case %d: %.7lf\n", tc, R * sin(pi/n) / ( 1.0 + sin(pi/n)));
	}

	return 0;
}