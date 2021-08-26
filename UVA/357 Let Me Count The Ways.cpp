#include <bits/stdc++.h>
#define whatIs(x)       cerr<< #x << " = "<< x<< endl;
using   namespace  std ;
typedef long   long LL ;

const vector<int> ar {1, 5, 10, 25, 50} ; 

const int mx = 30005 ;
LL dp[mx] ;

int main(){

	dp[0] = 1LL ;
	for(auto j : ar){
		for(int i = j ; i < mx ; i++)
			dp[i] += dp[i - j] ;
	}
	
	int n ;
	while(scanf("%d", &n) != EOF){
		if(dp[n] == 1)
			printf("There is only 1 way to produce %d cents change.\n", n) ;
		else
			printf("There are %lld ways to produce %d cents change.\n", dp[n], n) ;
	}

	return 0;
}