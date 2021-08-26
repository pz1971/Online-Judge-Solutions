#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int main(){

	int t;
	double ar[3];
	scanf("%d", &t);

	for(int tc=1; tc<=t; tc++){
		for(int i=0; i<3; i++){
			scanf("%lf", &ar[i]);
		}
		sort(ar, ar+3);
		printf("Case %d: ", tc);
		if(ar[2] >= ar[0] + ar[1] || ar[0] <= 0){
			printf("Invalid\n");
		}
		else{
			if(ar[0] == ar[2]){
				printf("Equilateral\n");
			}
			else if(ar[0] == ar[1] || ar[1] == ar[2]){
				printf("Isosceles\n");
			}
			else{
				printf("Scalene\n");
			}
		}
	}

	return 0;
}