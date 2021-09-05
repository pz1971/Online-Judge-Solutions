// SCC + DSU
#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 100005 ;
int n, m;
vector<int> g[mx], rg[mx] ;
vector<int> topo ;
int mark[mx], cmp[mx] ;

void dfs(int u){
	mark[u] = 1 ;
	for(auto i : g[u])
		if(!mark[i])
			dfs(i) ;
	topo.push_back(u) ;
}

void dfs2(int u, int id){
	mark[u] = 1 ;
	cmp[u] = id ;
	for(auto i : rg[u])
		if(!mark[i])
			dfs2(i, id) ;
}

int cnt = 0 ;	// number of SCC
int root[mx] ;

void init(){
	for(int i = 1 ; i <= cnt ; i++)
		root[i] = i ;
}

int find(int u){
	return root[u] == u ? u : root[u] = find(root[u]) ;
}

void merge(int u, int v){
	u = find(u) ;
	v = find(v) ;
	if(u != v){
		root[u] = v ;
	}
}

int main(){

	cin >> n >> m ;
	int a, b;
	while(m--){
		cin >> a >> b;
		g[a].push_back(b) ;
		rg[b].push_back(a) ;
	}

	for(int i = 1 ; i <= n ; i++)
		if(!mark[i])
			dfs(i) ;
	reverse(topo.begin(), topo.end()) ;

	memset(mark, 0, sizeof mark);
	
	for(auto i : topo){
		if(!mark[i])
			dfs2(i, ++cnt) ;
	}

	init() ;
	for(int i = 1 ; i <= n ; i++){
		for(auto j : g[i]){
			if(cmp[i] != cmp[j]){
				merge(cmp[i], cmp[j]) ;
			}
		}
	}

	int r = find(1) ;
	vector<int> ans ;
	for(int i = 1 ; i <= n ; i++){
		if(cmp[i] == r)
			ans.push_back(i) ;
	}
	cout << ans.size() << endl ;
	for(auto i : ans)
		cout << i << " " ;
	cout << endl ;

	return 0;
}