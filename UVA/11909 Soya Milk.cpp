#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int main(){

	double l, w, h, theta, v, dh;

	while(scanf("%lf %lf %lf %lf", &l, &w, &h, &theta) != EOF){
		theta = acos(-1.0) * theta / 180.0;
		dh = l * tan(theta);
		
		if(dh <= h){
			v = (.5 * (h+h-dh) * l) * w;
		}
		else{
			v = .5 * h*h / tan(theta) * w;
		}

		printf("%.3lf mL\n", v);
	}

	return 0;
}