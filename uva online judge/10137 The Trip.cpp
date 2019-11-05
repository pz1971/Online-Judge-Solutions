#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int main(){

	int n ;

	while(scanf("%d", &n) != EOF && n){

		double ar[n] ;
		double sum = 0.0;
		
		for(int i = 0 ; i < n ; i++){
			scanf("%lf", &ar[i]);
			sum += ar[i] ;
		}

		double average = sum / n ;
		double negDiff = 0.0, posDiff = 0.0 ;
		for(int i = 0 ; i < n ; i++){
			double diff = (LL)((average - ar[i]) * 100.0) / 100.0 ;
			
			if(diff >= 0.0)
				posDiff += diff ;
			else 
				negDiff -= diff ;
		}

		printf("$%.2lf\n", max(posDiff, negDiff)) ;
	}

	return 0;
}