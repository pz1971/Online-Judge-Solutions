// A very good explanation -> https://blog.habibrahman.me/dp/2017/07/21/LightOJ-1157-LCS-Revisited/
#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 1005 ;
const int mod = 1000007 ;

string a, b ;
int dp[mx][mx], cnt[mx][mx] ;

int LCS(){
	for(int i = 0 ; i <= a.size() ; i++){
		for(int j = 0 ; j <= b.size() ; j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0 ;
				cnt[i][j] = 1 ;
				continue ;
			}

			if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1 ;
				cnt[i][j] = cnt[i-1][j-1] ;
			}
			else {
				if(dp[i-1][j] > dp[i][j-1]){
					dp[i][j] = dp[i-1][j] ;
					cnt[i][j] = cnt[i-1][j] ;
				}
				else if(dp[i-1][j] < dp[i][j-1]){
					dp[i][j] = dp[i][j-1] ;
					cnt[i][j] = cnt[i][j-1] ;
				}
				else{
					dp[i][j] = dp[i-1][j] ;
					cnt[i][j] = cnt[i-1][j] + cnt[i][j-1] - (cnt[i-1][j-1] * (int)(dp[i][j] == dp[i-1][j-1])) ;
					cnt[i][j] = (cnt[i][j] + mod) % mod ;
				}
			}
		}
	}

	return cnt[a.size()][b.size()] ;
}

int main(){

	int t ;
	cin >> t ;
	for(int tc = 1 ; tc <= t ; tc++){
		cin >> a >> b ;
		cout<< "Case "<< tc<< ": " << LCS() << endl ;
	}

	return 0;
}