#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 1005 ;

class edge{
public: 
	int a, b, c ;
} ;

class cmp{
public:
	bool operator () (const edge &e1, const edge &e2){
		return e1.c < e2.c ;
	}
} ;

int p, n, m ;
int root[mx] ;

void init(){
	for(int i = 1 ; i <= n ; i++)
		root[i] = i ;
}

int find(int u){
	return root[u] == u ? u : root[u] = find(root[u]) ;
}

int insert(const edge &e){
	int u = find(e.a) ;
	int v = find(e.b) ;
	if(u != v){
		root[u] = v ;
		return e.c ;
	}
	return 0 ;
}

int main(){

	int t ;
	cin >> t ;

	for(int tc = 1 ; tc <= t ; tc++){
		cin >> p ;
		cin >> n ;
		cin >> m ;
		init() ;

		vector<edge> ar(m) ;
		for(auto &i : ar){
			cin >> i.a >> i.b >> i.c ;
			i.c *= p ;
		}
		sort(ar.begin(), ar.end(), cmp()) ;
		
		int ans = 0 ;
		for(const auto &i : ar){
			ans += insert(i) ;
		}
		cout << ans << endl ;
	}

	return 0;
}