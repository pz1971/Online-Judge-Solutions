#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int main(){

	int n;
	double ans;
	while(cin>> n && n){
		int ar[n];
		for(int i=0; i<n; i++){
			scanf("%d", &ar[i]);
		}
		double cnt = 0.0, total = (n*(n-1))/2.0;
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				if(__gcd(ar[i], ar[j]) == 1)
					cnt++;
			}
		}
		if(cnt == 0){
			printf("No estimate for this data set.\n");
		}
		else{
			ans = sqrt(total * 6.0 / cnt);
			printf("%.6lf\n", ans);
		}
	}

	return 0;
}