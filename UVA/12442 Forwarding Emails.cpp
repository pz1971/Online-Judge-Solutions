#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 50005 ;
int n ;
int adj[mx], mark[mx], stat[mx] ;

void init(){
	for(int i = 1 ; i <= n ; i++)
		adj[i] = mark[i] = stat[i] = 0 ;
}

void dfs(int u){
	mark[u] = 1 ;
	int ret = 1 ;
	
	if(!mark[adj[u]]){
		dfs(adj[u]) ;
		ret += stat[adj[u]] ;
	}
	
	mark[u] = 0 ;	// reset
	stat[u] = ret ;
}

int main(){

	int t ;
	cin >> t ;
	for(int tc = 1 ; tc <= t ; tc++){
		cin >> n ;
		init() ;

		int u, v ;
		for(int i = 0 ; i < n ; i++){
			cin >> u >> v ;
			adj[u] = v ;
		}

		int ans = 1, mxm = 0 ;
		for(int i = 1 ; i <= n ; i++){
			if(!stat[i])
				dfs(i) ;
			if(stat[i] > mxm){
				mxm = stat[i] ;
				ans = i ;
			}
		}

		cout<< "Case "<< tc<< ": " << ans << endl ;
	}

	return 0;
}