#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 1000005 ;

class edge{
public : 
	int u, v, c ;
} ;

class cmp{
public:
	bool operator() (const edge &a, const edge &b){
		return a.c < b.c ;
	}
} ;

int n, m ;
int root[mx] ;

void init(){
	for(int i = 0 ; i < n ; i++)
		root[i] = i ;
}

int find(int u){
	return root[u] == u ? u : root[u] = find(root[u]) ;
}

int insert(const edge &e){
	int u = find(e.u) ;
	int v = find(e.v) ;
	if(u != v){
		root[u] = v ;
		return e.c ;
	}
	return 0 ;
}

int main(){

	while(cin >> n >> m && (n || m)){
		init() ;

		vector<edge> ar(m) ;
		for(auto &i : ar){
			cin >> i.u >> i.v >> i.c ;
		}
		sort(ar.begin(), ar.end(), cmp()) ;

		int ans = 0 ;
		for(const auto &i : ar){
			ans = max(ans, insert(i)) ;
		}

		bool f = true ;
		int r = find(0) ;
		for(int i = 1 ; i < n ; i++){
			if(r != find(i)){
				f = false ;
				cout << "IMPOSSIBLE" << endl ;
				break ;
			}
		}
		if(f)
			cout << ans << endl ;
	}

	return 0;
}