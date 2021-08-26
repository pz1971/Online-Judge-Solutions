#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int dp[21][100005] ;

int main(){

	int n ;
	while(cin >> n){
		int t ;
		cin >> t ;
		
		int d[t+1] ;
		for(int i = 1 ; i <= t ; i++){
			cin >> d[i] ;

			for(int j = 1; j <= n ; j++){
				if(j - d[i] >= 0)
					dp[i][j] = max(dp[i-1][j] , dp[i-1][j - d[i]] + d[i]) ;
				else 
					dp[i][j] = dp[i-1][j] ;
			}
		}

		int tape = dp[t][n] ;
		set<int> tracks ;
		
		for(int i = t ; i > 0 ; i--){
			if(dp[i][tape] == dp[i-1][tape])
				continue ;
			tracks.insert(d[i]) ;
			tape -= d[i] ;
		}

		for(auto i: tracks)
			cout << i << " " ;
		cout << "sum:" << dp[t][n] << endl ;
	}

	return 0;
}