#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 1005 ;
int n, p[mx], w[mx] ;
int dp[mx][35] ;

void knapsack(){
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j < 33 ; j++){
			if(j - w[i] >= 0)
				dp[i][j] = max(dp[i-1][j], p[i] + dp[i-1][j - w[i]]) ;
			else
				dp[i][j] = dp[i-1][j] ;
		}
	}
}

int main(){

	int t;
	cin >> t ;

	while(t--){
		cin >> n ;
		for(int i = 1  ; i <= n; i++)
			cin >> p[i] >> w[i] ;
		
		knapsack() ;
		int g, mw ;
		cin >> g ;

		int ans = 0 ;
		while(g--){
			cin >> mw;
			ans += dp[n][mw] ;
		}
		cout << ans << endl ;
	}

	return 0;
}