#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

class edge {
public: 
	int a, b, c, id ;
} ;

class cmp{
public: 
	bool operator () (const edge &e1, const edge &e2){
		return e1.c < e2.c ;
	}
} ;

int n, m ;
int root[105] ;

void init(){
	for(int i = 1 ; i <= n ; i++)
		root[i] = i ;
}

int find(int u){
	return root[u] == u ? u : root[u] = find(root[u]) ;
}

bool insert(const edge &e){
	int u = find(e.a) ;
	int v = find(e.b) ;
	if(u != v){
		root[u] = v ;
		return true ;
	}
	return false ;
}

int main(){

	int t ;
	cin >> t ;

	while(t--){
		cin >> n >> m ;

		init() ;
		vector<edge> ar(m) ;
		int id = 0 ;

		for(auto &i : ar){
			cin >> i.a >> i.b >> i.c ;
			i.id = ++id ;
		}
		sort(ar.begin(), ar.end(), cmp()) ;

		int ans = 0 ;
		vector<int> selected ;
		for(const auto &i : ar){
			if(insert(i)){
				ans += i.c ;
				selected.push_back(i.id) ;
			}
		}

		int ans2 = INT_MAX ;
		for(auto i : selected){
			init() ;

			int cost = 0, cnt = 0 ;
			for(const auto &j : ar){
				if(i == j.id)	continue ;
				if(insert(j)){
					cost += j.c ;
					cnt++ ;
				}
			}

			if(cnt == n-1)
				ans2 = min(ans2, cost) ;
		}

		cout << ans << " " << ans2 << endl ;
	}

	return 0;
}