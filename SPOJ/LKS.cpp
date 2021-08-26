#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int main(){

	int n, k ;
	cin >> k >> n;

	int dp[2][k+5] ;
	int v[n + 5], w[n + 5] ;
	memset(dp, 0, sizeof dp);
	v[0] = w[0] = 0 ;

	for(int i = 1 ; i <= n ; i++)
		cin >> v[i] >> w[i] ;
	
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= k ; j++){
			if(j - w[i] < 0)
				dp[i & 1][j] = dp[(i-1) & 1][j] ;
			else
				dp[i & 1][j] = max(dp[(i-1) & 1][j], v[i] + dp[(i-1) & 1][j - w[i]]) ;
		}
	}

	cout << dp[n&1][k] << endl ;

	return 0;
}