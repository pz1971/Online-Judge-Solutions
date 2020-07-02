#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 5005 ;
int v, e ;
vector<int> g[mx], rg[mx] ;
vector<int> topo ;
int mark[mx], mark2[mx], cmp[mx], stat[mx] ;

void init(){
	topo.clear() ;
	for(int i = 1 ; i <= v ; i++){
		g[i].clear() ;
		rg[i].clear() ;
		mark[i] = 0 ;
		mark2[i] = 0 ;
		cmp[i] = 0 ;
		stat[i] = 1 ;
	}
}

void dfs(int u){
	mark[u] = 1 ;
	for(auto i : g[u]){
		if(!mark[i])
			dfs(i) ;
	}
	topo.push_back(u) ;
}

void dfs2(int u, int id){
	cmp[u] = id ;
	mark2[u] = 1 ;
	for(auto i : rg[u])
		if(!mark2[i])
			dfs2(i, id) ;
}

int main(){

	while(cin >> v && v){
		init() ;
		cin >> e ;
		int a, b ;
		while(e--){
			cin >> a >> b ;
			g[a].push_back(b) ;
			rg[b].push_back(a) ;
		}

		for(int i = 1 ; i <= v ; i++){
			if(!mark[i])
				dfs(i) ;
		}
		reverse(topo.begin(), topo.end()) ;
		
		int id = 0;
		for(auto i : topo){
			if(mark2[i] == 0)
				dfs2(i, ++id) ;
		}

		for(int i = 1 ; i <= v ; i++){
			for(auto j : g[i]){
				if(cmp[i] != cmp[j])
					stat[cmp[i]] = 0 ;
			}
		}

		for(int i = 1 ; i <= v ; i++)
			if(stat[cmp[i]])
				cout << i << " " ;
		cout << endl ;
	}

	return 0;
}