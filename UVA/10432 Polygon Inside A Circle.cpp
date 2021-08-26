#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;
const double pi = acos(-1.0);

int main(){

	double n, r;

	while(scanf("%lf %lf", &r, &n) != EOF){
		printf("%.3lf\n", .5*n*r*r*sin(2.0*pi/n));
	}

	return 0;
}