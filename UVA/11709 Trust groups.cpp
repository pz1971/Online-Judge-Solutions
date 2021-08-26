#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int p, t ;
map<string,vector<string>> g, rg ;
map<string,int> mark ;
vector<string> names, topo ;

void init(){
	names.clear() ;
	topo.clear() ;
	mark.clear() ;
	g.clear() ;
	rg.clear() ;
}

void dfs(string u){
	mark[u] = 1 ;
	for(auto i : g[u])
		if(!mark[i])
			dfs(i) ;
	topo.push_back(u) ;
}

void dfs2(string u){
	mark[u] = 1 ;
	for(auto i : rg[u])
		if(!mark[i])
			dfs2(i) ;
}

int main(){

	string a, b ;
	while(cin >> p >> t && (p || t)){
		cin.ignore() ;
		init() ;

		for(int i = 0 ; i < p ; i++){
			getline(cin, a) ;
			names.push_back(a) ;
		}

		while(t--){
			getline(cin, a) ;
			getline(cin, b) ;
			g[a].push_back(b) ;
			rg[b].push_back(a) ;
		}

		for(auto i : names){
			if(!mark[i])
				dfs(i) ;
		}
		reverse(topo.begin(), topo.end()) ;

		mark.clear() ;
		int cnt = 0 ;
		for(auto i : topo){
			if(!mark[i]){
				dfs2(i) ;
				cnt++ ;
			}
		}
		cout << cnt << endl ;
	}

	return 0;
}