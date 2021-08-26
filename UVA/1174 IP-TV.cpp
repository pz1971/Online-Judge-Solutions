#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 2005 ;

class edge{
public:
	string b, e ;
	int c ;
	void get(){
		cin >> b >> e >> c ;
	}
};

class cmp{
public: 
	bool operator () (const edge &u, const edge &v){
		return u.c < v.c ;
	}
};

int m, n ;
map<string, string> root ;

string find(string u){
	return root[u] == u ? u : root[u] = find(root[u]) ;
}

int insert(const edge &ed){
	string u = find(ed.b) ;
	string v = find(ed.e) ;
	if(u != v){
		root[u] = v ;
		return ed.c ;
	}
	return 0 ;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t ;
	cin >> t ;

	while(t--){
		cin >> m >> n ;
		root.clear() ;

		vector<edge> edges(n) ;
		for(auto &i : edges){
			i.get() ;
			root[i.b] = i.b ;
			root[i.e] = i.e ;
		}
		sort(edges.begin(), edges.end(), cmp()) ;

		int cost = 0 ;
		for(const auto &i : edges){
			cost += insert(i) ;
		}

		cout << cost << endl ;
		if(t) cout << endl ;
	}

	return 0;
}