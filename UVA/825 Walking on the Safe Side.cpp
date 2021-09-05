#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int test_case ;
	cin >> test_case ;
	
	while(test_case--){
		int w, n ;
		cin >> w >> n ;
		cin.ignore() ;

		vector<vector<int> > dp (w, vector<int> (n, 0)) ;
		
		stringstream ss ;
		string line ;

		for(int i = 1 ; i <= w ; i++){
			ss.clear() ;
			getline(cin, line) ;
			ss << line ;

			int r, c ;
			ss >> r ;
			while(ss >> c)
				dp[r-1][c-1] = -1 ;
		}

		dp[0][0] = 1 ;
		
		for(int i = 1 ; i < n ; i++)
			dp[0][i] = (dp[0][i] == -1 ? 0 : dp[0][i-1]) ;
		for(int i = 1 ; i < w ; i++)
			dp[i][0] = (dp[i][0] == -1 ? 0 : dp[i-1][0]) ;

		for(int i = 1 ; i < w ; i++){
			for(int j = 1 ; j < n ; j++){
				dp[i][j] = (dp[i][j] == -1 ? 0 : (dp[i-1][j] + dp[i][j-1])) ;
			}
		}

		cout << dp[w-1][n-1] << endl ;
		if(test_case)	cout << endl ;
	}

	return 0;
}