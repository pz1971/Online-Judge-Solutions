#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 10005 ;

class edge{
public: 
	int x, y, c ;
	edge(){
	}
	edge(int x, int y, int c){
		this-> x = x ;
		this-> y = y ;
		this-> c = c ;
	}
};

class cmp{
public:
	bool operator () (const edge &a, const edge &b){
		return a.c < b.c ;
	}
};

int N, M, A ;
int root[mx] ;

void init(){
	for(int i = 1 ; i <= N ; i++)
		root[i] = i ;
}

int find(int u){
	return root[u] == u ? u : root[u] = find(root[u]) ;
}

int insert(const edge &e){
	int a = find(e.x) ;
	int b = find(e.y) ;
	if(a != b){
		root[a] = b ;
		return e.c ;
	}
	return 0 ;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t ;
	cin >> t ;

	for(int tc = 1 ; tc <= t ; tc++){
		cin >> N >> M >> A ;
		init() ;

		vector<edge> ar ;

		int x, y, c ;
		while(M--){
			cin >> x >> y >> c ;
			if(c < A)
				ar.push_back(edge(x, y, c)) ;
		}

		int cost = 0 ;
		sort(ar.begin(), ar.end(), cmp()) ;
		for(const auto &i : ar){
			cost += insert(i) ;
		}

		map<int,int> mp ;	// disjoint set representatives
		for(int i = 1 ; i <= N ; i++){
			mp[ find(i) ] = 1 ;
		}

		cost += (A * (int) mp.size()) ;

		cout<< "Case "<< tc<< ": " << cost << " " << mp.size() << endl ;
	}

	return 0;
}