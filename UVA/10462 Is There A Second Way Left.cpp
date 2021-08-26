#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

class edge{
public :
	int a, b, c, id ;
} ;

class cmp{
public:
	bool operator () (const edge &u, const edge &v){
		return u.c < v.c ;
	}
} ;

int v, e ;
int root[105] ;

void init(){
	for(int i = 1 ; i <= v ; i++)
		root[i] = i ;
}

int find(int u){
	return root[u] == u ? u : root[u] = find(root[u]) ;
}

bool insert(const edge &ed){
	int x = find(ed.a) ;
	int y = find(ed.b) ;
	if(x != y){
		root[x] = y ;
		return true ;
	}
	return false ;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t ;
	cin >> t ;

	for(int tc = 1 ; tc <= t ; tc++){
		cin >> v >> e ;
		init() ;
		vector<edge> ar(e) ;
		int id = 0 ;
		for(auto &i : ar){
			cin >> i.a >> i.b >> i.c ;
			i.id = ++id ;
		}
		sort(ar.begin(), ar.end(), cmp()) ;

		// MST
		vector<edge> selected ;
		for(const auto &i : ar){
			if(insert(i)){
				selected.push_back(i) ;
			}
		}
		
		cout<< "Case #"<< tc<< " : " ;

		if(selected.size() < v-1){
			cout << "No way" << endl ;
			continue ;
		}
		else if(selected.size() == ar.size()){
			cout << "No second way" << endl ;
			continue ;
		}
		
		// 2nd MST
		int ans = INT_MAX ;
		for(const auto &i : selected){
			int cost = 0, cnt = 0 ;
			init() ;

			for(const auto &j : ar){
				if(j.id == i.id)	continue ;
				if(insert(j)){
					cnt++ ;
					cost += j.c ;
				}
			}

			if(cnt == v-1)
				ans = min(ans, cost) ;
		}

		cout << ans << endl ;
	}

	return 0;
}