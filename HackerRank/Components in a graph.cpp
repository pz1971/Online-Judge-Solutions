#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int n ;
int root[30005] ;

void init(){
	for(int i = 1 ; i <= n + n ; i++){
		root[i] = i ;
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

	if(a == b)
		return ;
	
	root[a] = b ;
}

int main(){

	cin >> n ;
	init() ;

	int u, v;
	for(int i = 0 ; i < n; i++){
		cin >> u >> v; 
		insert(u, v) ;
	}
	
	map<int,int> cnt ;
	for(int i = 1 ; i <= n + n ; i++){
		cnt[find(i)]++ ;
	}

	int mx ;
	mx = cnt.begin()->second ;
	for(auto i : cnt){
		mx = max(mx, i.second) ;
	}

	int mn = mx ;
	for(auto i : cnt){
		if(i.second != 1)
			mn = min(mn, i.second) ;
	}

	cout << mn << " " << mx << endl ;

	return 0;
}