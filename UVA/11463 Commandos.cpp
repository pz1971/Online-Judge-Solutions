#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 105 ;

int n ;
int g[mx][mx] ;

void init(){
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			g[i][j] = (i == j ? 0 : INT_MAX) ;
}

void floyd_warshall(){
	for(int k = 0 ; k < n ; k++){
		for(int i = 0 ; i < n ; i++){
			if(g[i][k] == INT_MAX)
				continue ;
			
			for(int j = 0 ; j < n ; j++){
				if(g[k][j] == INT_MAX)
					continue ;
				
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]) ;
			}
		}
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t ;
	cin >> t ;
	for(int tc = 1 ; tc <= t ; tc++){
		cin >> n ;
		init() ;

		int r ;
		cin >> r;
		
		int u, v; 
		while(r--){
			cin >> u >> v;
			g[u][v] = g[v][u] = 1 ;
		}

		floyd_warshall() ;
		
		int s, e ;
		cin >> s >> e ;

		int ans = 0 ;
		for(int i = 0 ; i < n ; i++){
			ans = max(ans, g[s][i] + g[i][e]) ;
		}

		cout<< "Case "<< tc<< ": " << ans << endl ;
	}

	return 0;
}