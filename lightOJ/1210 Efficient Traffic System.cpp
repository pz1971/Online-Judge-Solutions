#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 20005 ;
int n, m ;
vector<int> g[mx], rg[mx], topo ;
int mark[mx], cmp[mx] ;
bool in[mx], out[mx] ;

void init(){
	topo.clear() ;
	for(int i = 1 ; i <= n ; i++){
		g[i].clear() ;
		rg[i].clear() ;
		mark[i] = cmp[i] = 0 ;
	}
}

void dfs(int u){
	mark[u] = 1 ;
	for(auto i : g[u])
		if(!mark[i])
			dfs(i) ;
	topo.push_back(u) ;
}

void dfs2(int u, int id){
	cmp[u] = id ;
	for(auto i : rg[u])
		if(!cmp[i])
			dfs2(i, id) ;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t ;
	cin >> t ;
	for(int tc = 1 ; tc <= t ; tc++){
		cin >> n >> m ;
		init() ;

		int u, v ;
		while(m--){
			cin >> u >> v ;
			g[u].push_back(v) ;
			rg[v].push_back(u) ;
		}

		for(int i = 1 ; i <= n ; i++){
			if(!mark[i])
				dfs(i) ;
		}
		reverse(topo.begin(), topo.end()) ;

		int cnt = 0 ;
		for(auto i : topo){
			if(!cmp[i])
				dfs2(i, ++cnt) ;
		}

		if(cnt == 1){
			cout<< "Case "<< tc<< ": 0" << endl ;
			continue ;
		}

		for(int i = 1 ; i <= cnt ; i++)
			in[i] = out[i] = false ;
		
		for(int i = 1 ; i <= n ; i++){
			for(auto j : g[i]){
				if(cmp[i] != cmp[j]){
					in[ cmp[j] ] = out[ cmp[i] ] = true ;
				}
			}
		}

		u = v = 0 ;
		for(int i = 1 ; i <= cnt ; i++){
			u += (int)(!in[i]) ;
			v += (int)(!out[i]) ;
		}

		cout<< "Case "<< tc<< ": " << max(u, v) << endl ;
	}

	return 0;
}