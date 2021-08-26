#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 1e5 + 5 ;
vector<int> g[mx] ;
int vis[mx] ;

void clearAll(int n){
	for(int i = 1 ; i <= n ; i++){
		g[i].clear() ;
		vis[i] = 0 ;
	}
}

int DFS(int node){
	if(vis[node])
		return vis[node] ;

	vis[node] = 1 ;
	
	for(auto i : g[node]){
		vis[node] = max(vis[node], DFS(i) + 1) ;
	}
	return vis[node] ;
}

int main(){

	int t ;
	scanf("%d", &t);
	
	for(int tc = 1 ; tc <= t ; tc++){
		int n, e ;
		scanf("%d %d", &n, &e);
		clearAll(n) ;

		int u, v ;
		while(e--){
			scanf("%d %d", &u, &v);
			g[u].push_back(v) ;
		}

		int ans = 0 ;
		for(int i = 1 ; i <= n ; i++){
			ans = max(ans, DFS(i)) ;
		}
		printf("Case %d: %d\n", tc, ans);
	}

	return 0;
}