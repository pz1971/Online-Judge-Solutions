#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 200005 ;

class edge{
public:
	int x, y ;
	LL z;
} ar[mx];

class cmp{
public:
	bool operator () (const edge &a, const edge &b){
		return a.z < b.z ;
	}
};

int m, n ;
int root[mx] ;
LL cost ;

void init(){
	for(int i = 0 ; i < m ; i++)
		root[i] = i ;
	cost = 0 ;
}

int find(int u){
	return root[u] == u ? u : root[u] = find(root[u]) ;
}

void insert(const edge &e){
	int a = find(e.x) ;
	int b = find(e.y) ;

	if(a != b){
		root[b] = a ;
		cost += e.z ;
	}
}

int main(){

	while(cin >> m >> n){
		if(!(m || n))	break ;
		
		init() ;

		LL total = 0 ;
		for(int i = 0 ; i < n; i++){
			cin >> ar[i].x >> ar[i].y >> ar[i].z ;
			total += ar[i].z ;
		}
		
		sort(ar, ar + n, cmp()) ;
		for(int i = 0 ; i < n ; i++)
			insert(ar[i]) ;

		cout << total - cost << endl ;
	}

	return 0;
}