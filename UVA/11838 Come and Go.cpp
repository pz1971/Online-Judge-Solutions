#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 2005 ;
int n, m ;
vector<int> g[mx], rg[mx] ;
vector<int> topo ;
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
	for(auto i : g[u]){
		if(!mark[i])
			dfs(i) ;
	}
	topo.push_back(u) ;
}

void dfs2(int u){
	mark2[u] = 1 ;
	for(auto i : rg[u]){
		if(!mark2[i])
			dfs2(i) ;
	}
}

int main(){

	while(cin >> n >> m && (n || m)){
		init() ;
		int v, w, p ;
		while(m--){
			cin >> v >> w >> p ;
			
			g[v].push_back(w) ;
			rg[w].push_back(v) ;
			if(p == 2){
				g[w].push_back(v) ;
				rg[v].push_back(w) ;
			}
		}

		for(int i = 1 ; i <= n ; i++){
			if(!mark[i])
				dfs(i) ;
		}
		reverse(topo.begin(), topo.end()) ;

		bool g = 1 ;
		dfs2(topo.front()) ;
		for(int i = 1 ; i < topo.size() ; i++)
			if(!mark2[topo[i]]){
				g = 0 ;
				break ;
			}
		cout << g << endl ;
	}

	return 0;
}