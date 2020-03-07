#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int dp[50005] ;
int v[105] ;

int main(){

	int t ;
	cin >> t ;

	while(t--){
		int m ;
		cin >> m ;
		
		int sum = 0 ;
		for(int i = 1 ; i <= m ; i++){
			cin >> v[i] ;
			sum += v[i] ;
		}

		int k = sum / 2 ;
		for(int i = 0 ; i <= k ; i++)	dp[i] = 0 ;

		for(int i = 1 ; i <= m ; i++){
			for(int j = k ; j >= v[i] ; j--){
				dp[j] = max(dp[j], dp[j - v[i]] + v[i]) ;
			}
		}

		int mx = 0 ;
		for(int i = 0 ; i <= k ; i++)
			mx = max(mx, dp[i]) ;
		
		cout << (sum - mx) - mx << endl ;
	}

	return 0;
}