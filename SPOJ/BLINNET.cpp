#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 10005 ;

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

int n ;
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

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int s ;
	cin >> s ;

	while(s--){
		cin >> n;
		init() ;
		string str ;
		vector<edge> ar ;
		
		for(int i = 1 ; i <= n; i++){
			cin >> str ;
			int p ;
			cin >> p ;
			while(p--){
				ar.push_back(edge()) ;
				ar.back().a = i ;
				cin >> ar.back().b >> ar.back().c ;
			}
		}

		sort(ar.begin(), ar.end(), cmp()) ;
		int ans = 0 ;
		for(const auto &i : ar)
			ans += insert(i) ;
		cout << ans << endl ;
	}

	return 0;
}