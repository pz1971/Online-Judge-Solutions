#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int inf = 1e9 ;

int cost[3][10] ;
int x, y ;

pair<int, int> func(){
	if(x == y) return make_pair(0, 0) ;
	
	vector<pair<int, int> > dp (y + 1, {inf, inf}) ;	// cost, press

	dp[x] = {0, 0} ;
	if(x != 0)
		dp[0] = {cost[2][0], 1} ; // cost of multiplying with 0 ;
	
	for(int i = 0 ; i <= y ; i++){
		for(int j = 0 ; j < 10 ; j++){
			if((i * 10) + j <= y){
				int t = i * 10 + j ;
				dp[t] = min(dp[t], {(dp[i].first + cost[0][j]) , (dp[i].second + 1)}) ;
			}
			if(i + j <= y){
				int t = i + j ;
				dp[t] = min(dp[t], {(dp[i].first + cost[1][j]) , (dp[i].second + 1)}) ;
			}
			if(i * j <= y){
				int t = i * j ;
				dp[t] = min(dp[t], {(dp[i].first + cost[2][j]) , (dp[i].second + 1)}) ;
			}
		}
	}

	return dp[y] ;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int tc = 0 ;

	while(cin >> x >> y){
		for(int i = 0 ; i < 3 ; i++)
			for(int j = 0 ; j < 10 ; j++)
				cin >> cost[i][j] ;

		pair<int, int> ans = func() ;
		cout<< "Case "<< ++tc<< ": " << ans.first << " " << ans.second << endl ;
	}

	return 0;
}