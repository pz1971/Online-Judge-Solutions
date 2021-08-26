#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int n, m ;
int root[30005] ;

void init(){
	for(int i = 0 ; i < n ; i++){
		root[i] = i ;
	}
}

int find(int u){
	return (root[u] == u) ? u : (root[u] = find(root[u])) ;
}

void insert(int u, int v){
	u = find(u) ;
	v = find(v) ;
	if(u != v){
		root[v] = u ;
	}
}

int main(){

	while(cin >> n >> m){
		if(!(n || m))	break ;
		init() ;
		while(m--){
			int k ;
			cin >> k ;

			int i, j ;
			cin >> i ;
			while(--k){
				cin >> j ;
				insert(i, j) ;
			}
		}

		int cnt = 0;
		for(int i = 0 ; i < n ; i++){
			if(find(i) == find(0))
				cnt++ ;
		}
		cout << cnt << endl ;
	}

	return 0;
}