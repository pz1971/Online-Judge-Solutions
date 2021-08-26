#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int n ;
vector<vector<int> > g ;

int ans = 0 ;
vector<int> vis ;

int dfs(int u){
	vis[u] = 1 ;
	
	int x, mx = 0, smx = 0 ;
	for(auto i : g[u]){
		if(vis[i])
			continue ;

		x = dfs(i) ;
		if(x >= mx){
			smx = mx ;
			mx = x ;
		}
		else if(x > smx)
			smx = x ;
	}
	
	ans = max(ans, mx + smx) ;
	
	return mx + 1 ;
}

int main(){

	cin >> n ;
	g = vector<vector<int> > (n + 1, vector<int> ()) ;
	vis = vector<int> (n + 1, 0) ;

	int u, v ;
	for(int i = 1 ; i < n ; i++){
		cin >> u >> v ;
		g[u].push_back(v) ;
		g[v].push_back(u) ;
	}

	dfs(1) ;
	cout << ans << endl ;

	return 0;
}