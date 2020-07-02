#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 100005 ;
int n, m ;
vector<int> g[mx] ;
int mark[mx], mark2[mx] ;
vector<int> topo ;

void init(){
	for(int i = 1 ; i <= n ; i++){
		mark[i] = mark2[i] = 0 ;
		g[i].clear() ;
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
	for(auto i : g[u])
		if(!mark2[i])
			dfs2(i) ;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t ;
	cin >> t ;
	while(t--){
		cin >> n >>  m ;
		init() ;
		int a, b ;
		while(m--){
			cin >> a >> b ;
			g[a].push_back(b) ;
		}

		// sort topologically
		for(int i = 1 ; i <= n ; i++)
			if(!mark[i])
				dfs(i) ;
		reverse(topo.begin(), topo.end()) ;

		// knock down
		int cnt = 0 ;
		for(auto i : topo){
			if(!mark2[i]){
				dfs2(i) ;
				cnt++ ;
			}
		}
		cout << cnt << endl ;
	}

	return 0;
}