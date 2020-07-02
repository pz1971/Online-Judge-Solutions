#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int n, m ;
map<string,vector<string>> g, rg ; 
map<string,int> mark ;
map<int, vector<string>> cmp ;
vector<string> topo ;

void dfs(string u){
	mark[u] = 1 ;
	for(auto i : g[u])
		if(mark[i] == 0)
			dfs(i) ;
	topo.push_back(u) ;
}

void dfs2(string u, int id){
	cmp[id].push_back(u) ;
	mark[u] = 1 ;
	for(auto i : rg[u]){
		if(mark[i] == 0)
			dfs2(i, id) ;
	}
}

int main(){

	string a, b ;
	int tc = 0 ;
	while(cin >> n >> m && (n || m)){
		g.clear() ;
		rg.clear() ;
		mark.clear() ;
		cmp.clear() ;
		topo.clear() ;

		while(m--){
			cin >> a >> b ;
			g[a].push_back(b) ;
			rg[b].push_back(a) ;
		}

		for(auto i : g){
			if(mark[i.first] == 0)
				dfs(i.first) ;
		}
		reverse(topo.begin(), topo.end()) ;

		mark.clear() ;
		int id = 0 ;
		for(auto i : topo){
			if(mark[i] == 0)
				dfs2(i, ++id) ;
		}

		if(tc) cout << endl ;
		cout << "Calling circles for data set " << ++tc << ":" << endl ;
		for(int i = 1 ; i <= id ; i++){
			cout << cmp[i][0] ;
			for(int j = 1 ; j < cmp[i].size() ; j++)
				cout << ", " << cmp[i][j] ;
			cout << endl ;
		}
	}

	return 0;
}