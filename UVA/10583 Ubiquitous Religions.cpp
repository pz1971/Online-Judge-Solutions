#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int n, m ;
int root[50005] ;

void init(){
	for(int i = 1 ; i <= n ; i++)
		root[i] = i ;
}

int find(int u){
	return (root[u] == u) ? u : (root[u] = find(root[u])) ;
}

void insert(int u, int v){
	u = find(u) ;
	v = find(v) ;
	if(u != v)
		root[u] = v ;
}

int main(){

	int tc = 1 ;
	while(cin >> n >> m){
		if(!(n || m))	break ;
		init() ;
		
		int i, j ;
		while(m--){
			cin >> i >> j ;
			insert(i, j) ;
		}

		set<int> st ;
		for(int i = 1 ; i <= n; i++)
			st.insert(find(i)) ;
		cout<< "Case "<< tc++ << ": " << st.size() << endl ;
	}

	return 0;
}