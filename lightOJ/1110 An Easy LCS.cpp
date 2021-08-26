#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 105 ;
string a, b ;
int dp[mx][mx] ;
string ss[mx][mx] ;

string LCS(){
	for(int i = 0 ; i <= a.size() ; i++){
		for(int j = 0 ; j <= b.size() ; j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0 ;
				ss[i][j].clear() ;
				continue ;
			}
			
			if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1; 
				ss[i][j] = ss[i-1][j-1] + a[i-1] ;
			}
			else{
				if(dp[i-1][j] > dp[i][j-1]){
					dp[i][j] = dp[i-1][j] ;
					ss[i][j] = ss[i-1][j] ;
				}
				else if(dp[i-1][j] < dp[i][j-1]){
					dp[i][j] = dp[i][j-1] ;
					ss[i][j] = ss[i][j-1] ;
				}
				else{
					dp[i][j] = dp[i][j-1] ;
					ss[i][j] = min(ss[i-1][j], ss[i][j-1]) ;
				}
			}
		}
	}
	
	return (dp[a.size()][b.size()] == 0 ? ":(" : ss[a.size()][b.size()]) ;
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