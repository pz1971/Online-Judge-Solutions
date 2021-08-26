#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 105 ;

class edge{
public:
	int u, v, w;
};

class cmp{
public:
	bool operator () (const edge &a, const edge &b){
		return a.w < b.w ;
	}
};

class cmp2{
public:
	bool operator () (const edge &a, const edge &b){
		return a.w > b.w ;
	}
};

int n ;
int root[mx] ;
int cost ;

void init(){
	for(int i = 0 ; i <= n ; i++)
		root[i] = i ;
	cost = 0 ;
}

int find(int u){
	return root[u] == u ? u : root[u] = find(root[u]) ;
}

void insert(const edge &e){
	int a = find(e.u) ;
	int b = find(e.v) ;

	if(a != b){
		root[b] = a ;
		cost += e.w ;
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t ;
	cin >> t ;
	edge wire ;

	for(int tc = 1 ; tc <= t ; tc++){
		cin >> n ;
		vector<edge> ar ;

		while(cin >> wire.u >> wire.v >> wire.w){
			if(!(wire.u || wire.v || wire.w))
				break ;
			ar.push_back(wire) ;
		}

		init() ;
		sort(ar.begin(), ar.end(), cmp()) ;
		for(const auto &i : ar){
			insert(i) ;
		}
		int c1 = cost ;

		init() ;
		sort(ar.begin(), ar.end(), cmp2()) ;
		for(const auto &i : ar){
			insert(i) ;
		}
		int c2 = cost ;

		if((c1 + c2) % 2 == 0)
			cout<< "Case "<< tc<< ": " << (c1 + c2) / 2 << endl ;
		else 
			cout<< "Case "<< tc<< ": " << (c1 + c2) << "/2" << endl ;
	}

	return 0;
}
