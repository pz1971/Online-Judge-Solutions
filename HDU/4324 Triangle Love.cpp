#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 2005 ;
int n ;
vector<int> g[mx], rg[mx], topo ;
int vis[mx], mark[mx], mark2[mx] ;

void init(){
	for(int i = 0 ; i < n; i++){
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

bool dfs2(int u, int v){
	mark2[u] = 1;
	vis[u] = v ;
	bool ret = false ;
	
	for(auto i : rg[u]){
		if(vis[i]){
			ret |= (bool) (v - vis[i] == 2) ;
		}
		else if(!mark2[i]){
			ret |= dfs2(i, v+1) ;
		}
		if(ret) break ;
	}
	vis[u] = 0 ;

	return ret ;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t ;
	cin >> t ;
	for(int tc = 1 ; tc <= t ; tc++){
		cin >> n ;
		init() ;

		string s ;
		for(int i = 0 ; i < n ; i++){
			cin >> s ;
			for(int j = 0 ; j < n ; j++){
				if(s[j] == '1'){
					g[i].push_back(j) ;
					rg[j].push_back(i) ;
				}
			}
		}

		for(int i = 0 ; i < n ; i++)
			if(!mark[i])
				dfs(i) ;
		reverse(topo.begin(), topo.end()) ;

		bool f = false ;
		for(auto i : topo){
			if(!mark2[i]){
				f |= dfs2(i, 1) ;
				if(f)	break ;
			}
		}

		cout<< "Case #"<< tc<< ": " << (f ? "Yes" : "No") << endl ;
	}

	return 0;
}