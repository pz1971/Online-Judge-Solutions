#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int k, m ;
int a[55], b[55] ;
int dp[55][1005] ;

int knapsack(){
	for(int i = 1; i <= m; i++){
		for(int j = 1 ; j <= k ; j++){
			if(j - a[i] < 0)
				dp[i][j] = dp[i-1][j] ;
			else 
				dp[i][j] = max(dp[i-1][j], b[i] + dp[i-1][j - a[i]]) ;
		}
	}
	return dp[m][k] ;
}

int main(){

	int n ;
	cin >> n ;

	while(n--){
		cin >> k >> m ;
		for(int i = 1 ; i <= m ; i++)
			cin >> a[i] >> b[i] ;
		cout << "Hey stupid robber, you can get " << knapsack() << "." << endl ;
	}

	return 0;
}