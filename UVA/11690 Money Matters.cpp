#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int par[10005], ar[10005] ;
int n, m ;

void init(){
	for(int i = 0 ; i < n ; i++)
		par[i] = i ;
}

int find(int u){
	return (par[u] == u) ? u : (par[u] = find(par[u])) ;
}

void insert(int u, int v){
	int a = find(u) ;
	int b = find(v) ;

	if(a != b){
		par[b] = a ;
		ar[a] += ar[b] ;
	}
}

int main(){

	int t ;
	cin >> t ;

	while(t--){
		cin >> n >> m ;
		init() ;
		for(int i = 0 ; i < n; i++)
			cin >> ar[i] ;
		
		int x, y ;
		while(m--){
			cin >> x >> y ;
			insert(x, y) ;
		}

		bool f = true ;
		for(int i = 0 ; f && i < n ; i++){
			f &= (ar[find(i)] == 0) ;
		}

		cout << (f ? "POSSIBLE" : "IMPOSSIBLE") << endl ;
	}

	return 0;
}