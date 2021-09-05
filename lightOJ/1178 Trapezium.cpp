#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int main(){

	int t;
	scanf("%d", &t);
	double a, b, c, d, f, s, del, h;
	for(int tc = 1; tc<=t; tc++){
		scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
		if(c > a){
			swap(a, c);
			swap(b, d);
		}
		f = a - c;
		s = (b+d+f)/2.0;
		del = sqrt(s * (s - b) * (s - d) * (s - f));
		h = 2.0 * del / f;
		printf("Case %d: %.6lf\n", tc, del + c * h);
	}

	return 0;
}