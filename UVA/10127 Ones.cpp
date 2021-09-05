#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

const int MX = 10007 ;
int ar[MX] ;

int claculate_for(const int n){
	int rem = 1, cnt = 1 ;
	while(rem){
		rem = (rem * 10 + 1) % n ;
		cnt++ ;
	}
	return cnt ;
}

void pre_processing(){
	for(int i = 3 ; i < MX ; i += 2){
		if(i % 5 == 0)	continue ;
		ar[i] = claculate_for(i) ;
	}
}

int main(){

	pre_processing() ;

	int n ;
	while(scanf("%d", &n) != EOF){
		printf("%d\n", ar[n]);
	}

	return 0;
}