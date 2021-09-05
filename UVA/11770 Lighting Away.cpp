#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 10005;
int n, m ;
vector<int> g[mx] ;
int mark[mx], mark2[mx] ;
vector<int> topo ;

void init(){
	for(int i = 1 ; i <= n ; i++){
		g[i].clear() ;
		mark[i] = 0 ;
		mark2[i] = 0 ;
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
	for(auto i : g[u]){
		if(!mark2[i])
			dfs2(i) ;
	}
}

int main(){

	int t ;
	cin >> t ;
	for(int tc = 1 ; tc <= t ; tc++){
		cin >> n >> m ;
		init() ;

		int a, b; 
		while(m--){
			cin >> a >> b ;
			g[a].push_back(b) ;
		}

		for(int i = 1 ; i <= n ; i++)
			if(!mark[i])
				dfs(i) ;
		reverse(topo.begin(), topo.end()) ;
		
		int cnt = 0 ;
		for(auto i : topo){
			if(!mark2[i]){
				dfs2(i) ;
				cnt++ ;
			}
		}
		cout<< "Case "<< tc<< ": " << cnt << endl ;
	}

	return 0;
}