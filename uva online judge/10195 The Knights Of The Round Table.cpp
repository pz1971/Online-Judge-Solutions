#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int main(){

	double a, b, c, s, del, r;

	while(scanf("%lf %lf %lf", &a, &b, &c) != EOF){
		s = (a + b + c) / 2.0;
		del = sqrt(s * (s - a) * (s - b) * (s - c));
		del == 0 ?	r = 0 :	r = del / s;
		printf("The radius of the round table is: %.3lf\n", r);
	}

	return 0;
}