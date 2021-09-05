#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

class node{
public:
	int u, v, w ;
	node(int u, int v, int w){
		this->u = u ;
		this->v = v ;
		this-> w = w ;
	}
} ;

class cmp{
public:
	bool operator () (const node &n1, const node &n2){
		return (n1.w < n2.w) ;
	}
} ;

const int mx = 100005 ;
int n ;

int par[mx] ;
int cnt[mx] ;
map<int,LL> C ;

void init(){
	for(int i = 1 ; i <= n ; i++){
		par[i] = i ;
		cnt[i] = 1 ;
	}
}

int find(int u){
	if(par[u] == u){
		return u ;
	}
	
	return par[u] = find(par[u]) ;
}

void insert(int u, int v, int w){
	int a = find(u) ;
	int b = find(v) ;

	if(a != b){
		par[b] = a ;
		C[w] += (LL)cnt[a] * (LL)cnt[b] ;
		cnt[a] += cnt[b] ;
	}
}

int main(){

	int q ;
	cin >> n >> q ;

	int u, v, w ;
	vector<node> edges ;

	for(int i = 1 ; i < n; i++){
		cin >> u >> v >> w ;
		edges.push_back(node(u, v, w)) ;
	}
	sort(edges.begin(), edges.end(), cmp()) ;

	init() ;
	for(const auto &i : edges){
		insert(i.u, i.v, i.w) ;
	}

	C[0] = 0LL ;

	auto it = C.begin() ;
	auto it2 = it ;
	it2++ ;
	for( ; it2 != C.end() ; it++, it2++){
		it2 -> second += it -> second ;
	}

	int L, R ;
	while(q--){
		cin >> L >> R ;
		it = C.upper_bound(R) ;
		it2 = C.lower_bound(L) ;

		it-- ;	it2-- ;
		cout << (it->second - it2->second) << endl ;
	}

	return 0;
}