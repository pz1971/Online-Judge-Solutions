#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 55 ;

class edge{
public:
	int u, v, w;
	edge(){
	}
	edge(int u, int v, int w){
		this-> u = u ;
		this-> v = v ;
		this-> w = w ;
	}
};

class cmp{
public:
	bool operator () (const edge &a, const edge &b){
		return a.w < b.w ;
	}
};

int n ;
int root[mx] ;
int cost ;

void init(){
	for(int i = 0 ; i < n ; i++)
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

	for(int tc = 1 ; tc <= t ; tc++){
		cin >> n ;
		init() ;
		vector<edge> ar ;

		int total = 0 ;
		int w ;

		for(int i = 0 ; i < n;  i++){
			for(int j = 0 ; j < n ; j++){
				cin >> w ;
				total += w ;
				if(w)
					ar.push_back(edge(i, j, w)) ;
			}
		}

		sort(ar.begin(), ar.end(), cmp()) ;
		for(const auto &i : ar){
			insert(i) ;
		}

		int r = find(0) ;
		bool f = true ;
		for(int i = 1 ; i < n ; i++)
			if(find(i) != r){
				f = false ;
				break ;
			}

		if(f){
			cout<< "Case "<< tc<< ": " << total - cost << endl ;
		}
		else {
			cout<< "Case "<< tc<< ": -1" << endl ;
		}
	}

	return 0;
}
