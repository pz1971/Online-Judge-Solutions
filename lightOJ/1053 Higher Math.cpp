#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int main(){

	int t;
	scanf("%d", &t);
	double ar[3];
	bool y;
	
	for(int tc = 1; tc<=t; tc++){
		for(int i=0; i<3; i++){
			scanf("%lf", &ar[i]);
		}
		sort(ar, ar+3);
		if(ar[0]*ar[0] + ar[1]*ar[1] == ar[2]*ar[2]){
			y = true;
		}
		else{
			y = false;
		}
		printf("Case %d: ", tc);
		printf(y == true ? "yes\n" : "no\n");
	}

	return 0;
}