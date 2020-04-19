#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 30005 ;
int n, m ;
int par[mx] ;

void reset(){
	for(int i = 1 ; i <= n ; i++)
		par[i] = i ;
}

int find(int u){
	if(par[u] == u)
		return u ;
	return par[u] = find(par[u]) ;
}

void set_union(int a, int b){
	int u = find(a) ;
	int v = find(b) ;
	if(u != v){
		par[v] = u ;
	}
}

int main(){

	int t ;
	cin >> t ;

	while(t--){
		cin >> n >> m ;
		reset() ;
		int a, b ;
		while(m--){
			cin >> a >> b ;
			set_union(a, b) ;
		}

		map<int,int> cnt ;
		int ans = 0 ;
		for(int i = 1 ; i <= n ; i++){
			ans = max(ans, ++cnt[find(i)]) ;
		}
		cout << ans << endl ;
	}

	return 0;
}