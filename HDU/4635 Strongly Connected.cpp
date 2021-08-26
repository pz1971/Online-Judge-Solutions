#include <bits/stdc++.h>
#define whatIs(x)       cerr<< #x << " = "<< x<< endl;
using   namespace  std ;
typedef long   long LL ;

const int mx = 100005 ;

int n, m ;
vector<int> g[mx], rg[mx] ;
vector<int> topo ;
int mark[mx], cmp[mx] ;
LL scc[mx] ;

void init(){
	for(int i = 1 ; i <= n ; i++){
		g[i].clear() ;
		rg[i].clear() ;
		mark[i] = cmp[i] = scc[i] = 0 ;
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

void dfs2(int u, int id){
	cmp[u] = id ;
	scc[id]++ ;
	for(auto i : rg[u]){
		if(!cmp[i])
			dfs2(i, id) ;
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t ;
	cin >> t ;
	for(int tc = 1 ; tc <= t ; tc++){
		cin >> n >> m ;
		init() ;

		int x, y ;
		for(int i = 0 ; i < m ; i++){
			cin >> x >> y ;
			g[x].push_back(y) ;
			rg[y].push_back(x) ;
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
		
		if(cnt == 1){	// already strongly connected
			cout<< "Case "<< tc<< ": " << -1 << endl ;
			continue ;
		}

		int in[cnt+1], out[cnt+1] ;
		memset(in, 0, sizeof in) ;
		memset(out, 0, sizeof out) ;

		for(int i = 1 ; i <= n ; i++){
			for(auto j : g[i]){
				if(cmp[i] != cmp[j]){
					out[cmp[i]]++ ;
					in[cmp[j]]++ ;
				}
			}
		}

		LL a = LLONG_MAX ;
		for(int i = 1 ; i <= cnt ; i++){
			if(out[i] == 0 || in[i] == 0)
				a = min(a, scc[i]) ;
		}

		if(a == LLONG_MAX){
			cout<< "Case "<< tc<< ": " << 0 << endl ;
			continue ;
		}

		LL b = n - a ;
		LL ans = a * (a - 1LL) + b * (b - 1LL) + a * b - (LL) m ;
		cout<< "Case "<< tc<< ": " << ans << endl ;
	}

	return 0;
}