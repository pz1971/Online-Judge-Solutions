#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

class edge{
public: 
	string a, b ;
	int c ;
} ;
class cmp{
public:
	bool operator () (const edge &u, const edge &v){
		return u.c < v.c ;
	}
} ;

int S, C ;
map<string,string> root ;

string find(string u){
	return root[u] == u ? u : root[u] = find(root[u]) ;
}

int insert(const edge &e){
	string u = find(e.a) ;
	string v = find(e.b) ;
	if(u != v){
		root[u] = v ;
		return e.c ;
	}
	return 0 ;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	while(cin >> S >> C && (S || C)){
		root.clear() ;
		string str ;
		for(int i = 0 ; i < S ; i++){
			cin >> str ;
			root[str] = str ;
		}

		vector<edge> ar(C) ;
		for(auto &i : ar)
			cin >> i.a >> i.b >> i.c ;
		sort(ar.begin(), ar.end(), cmp()) ;

		int ans = 0 ;
		for(const auto &i : ar){
			ans += insert(i) ;
		}

		bool f = true ;
		cin >> str ;
		str = find(str) ;

		for(auto i : root){
			if(str != find(i.first)){
				f = false ;
				cout << "Impossible" << endl ;
				break ;
			}
		}

		if(f)
			cout << ans << endl ;
	}

	return 0;
}