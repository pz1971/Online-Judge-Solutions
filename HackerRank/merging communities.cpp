#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 100005 ;
int n ;
int root[mx], cnt[mx] ;

void init(){
	for(int i = 1 ; i <= n ; i++){
		root[i] = i ;
		cnt[i] = 1 ;
	}
}

int find(int u){
	if(root[u] == u)
		return u ;
	return root[u] = find(root[u]) ;
}

void insert(int u, int v){
	int a = find(u) ;
	int b = find(v) ;

	if(a != b){
		root[b] = a ;
		cnt[a] += cnt[b] ;
	}
}

int main(){

	int q ;
	cin >> n >> q ;
	init() ;

	string type ;
	int i, j ;

	while(q--){
		cin >> type ;
	
		if(type == "M"){
			cin >> i >> j ;
			insert(i, j) ;
		}
		else{
			cin >> i ;
			cout << cnt[find(i)] << endl ;
		}
	}

	return 0;
}