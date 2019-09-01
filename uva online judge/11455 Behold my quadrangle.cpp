#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int main(){

	int t;
	double ar[4];
	scanf("%d", &t);
	while(t--){
		for(int i=0; i<4; i++){
			scanf("%lf", &ar[i]);
		}
		sort(ar, ar+4);
		if(ar[0] + ar[1] + ar[2] <= ar[3] || ar[0] == 0){
			printf("banana\n");
		}
		else if(ar[0] == ar[3]){
			printf("square\n");
		}
		else if(ar[0] == ar[1] && ar[2] == ar[3]){
			printf("rectangle\n");
		}
		else{
			printf("quadrangle\n");
		}
	}

	return 0;
}