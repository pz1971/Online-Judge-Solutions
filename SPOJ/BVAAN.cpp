#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 105 ;
const int min_inf = -1e9 ;

string a, b ;
int k ;
int dp[mx][mx][mx] ;

int LCS(int i, int j, int len){
	if(len >= k)	return 0 ;
	
	if(i >= a.size() || j >= b.size())
		return min_inf ;
	
	if(dp[i][j][len] != -1)
		return dp[i][j][len] ;
	
	int ret = min_inf ;
	
	if(a[i] == b[j]){
		 ret = LCS(i + 1, j + 1, len + 1) + (int) a[i] ;
	}
	ret = max(ret, LCS(i + 1, j, len)) ;
	ret = max(ret, LCS(i, j + 1, len)) ;

	return dp[i][j][len] = ret ;
}

int main(){

	int t ;
	cin >> t ;
	while(t--){
		cin >> a >> b >> k ;
		
		memset(dp, -1, sizeof dp) ;
		cout << max(0, LCS(0, 0, 0)) << endl ;
	}

	return 0;
}