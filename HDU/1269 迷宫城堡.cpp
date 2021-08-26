#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 10005 ;
int n, m ;
vector<int> g[mx], rg[mx], topo ;
int mark[mx], mark2[mx] ;

void init(){
	for(int i = 1 ; i <= n ; i++){
		g[i].clear() ;
		rg[i].clear() ;
		mark[i] = mark2[i] = 0 ;
	}
	topo.clear() ;
}

void dfs(int u){
	mark[u] = 1 ;
	for(auto i : g[u])
		if(!mark[i])
			dfs(i) ;
	topo.push_back(u) ;
}

void dfs2(int u){
	mark2[u] = 1 ;
	for(auto i : rg[u])
		if(!mark2[i])
			dfs2(i) ;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	while(cin >> n >> m && (n | m)){
		init() ;

		int u, v ;
		while(m--){
			cin >> u >> v ;
			g[u].push_back(v) ;
			rg[v].push_back(u) ;
		}

		for(int i = 1; i <= n; i++)
			if(!mark[i])
				dfs(i) ;
		
		int cnt = 0 ;
		for(int i = n-1 ; i >= 0 ; i--){
			if(!mark2[topo[i]]){
				cnt++ ;
				dfs2(topo[i]) ;
			}
			if(cnt > 1)	break ;
		}

		cout << (cnt > 1 ? "No" : "Yes") << endl ;
	}

	return 0;
}