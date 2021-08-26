#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int main(){

	int s, n ;
	cin >> s >> n ;

	LL dp[s+1] ;
	memset(dp, 0, sizeof dp);

	LL sz[n+1], v[n+1] ;
	for(int i = 0 ; i < n ; i++){
		cin >> sz[i] >> v[i] ;

		for(int j = s ; j >= sz[i] ; j--)
			dp[j] = max(dp[j], dp[j - sz[i]] + v[i]) ;
	}

	LL ans = 0 ;
	for(int i = 0 ; i <= s ; i++)
		ans = max(ans, dp[i]) ;
	cout << ans << endl ;

	return 0;
}