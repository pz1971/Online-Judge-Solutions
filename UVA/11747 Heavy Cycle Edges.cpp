#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 1005 ;

class edge{
public : 
	int u, v, w ;
} ;

class cmp{
public:
	bool operator() (const edge &a, const edge &b){
		return a.w < b.w ;
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

bool insert(const edge &e){
	int u = find(e.u) ;
	int v = find(e.v) ;
	if(u != v){
		root[u] = v ;
		return 1 ;
	}
	return 0 ;
}

int main(){

	while(cin >> n >> m && (n || m)){
		init() ;

		vector<edge> ar(m) ;
		for(auto &i : ar){
			cin >> i.u >> i.v >> i.w ;
		}
		sort(ar.begin(), ar.end(), cmp()) ;

		vector<int> wt ;
		int x ;
		for(const auto &i : ar){
			x = insert(i) ;
			if(x == 0)
				wt.push_back(i.w) ;
		}

		for(int i = 0 ; i < wt.size() ; i++)
			cout << wt[i] << " \n"[i == wt.size()-1] ;
		if(wt.empty())	cout << "forest\n" ;
	}

	return 0;
}