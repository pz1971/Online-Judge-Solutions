#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 100005 ;
int n ;
int root[mx] ;

void init(){
	for(int i = 1 ; i <= n ; i++)
		root[i] = i ;
}

int find(int u){
	return root[u] == u ? u : root[u] = find(root[u]) ;
}

void insert(int u, int v){
	u = find(u) ;
	v = find(v) ;
	if(u != v)
		root[u] = v ;
}

int main(){

	int t ;
	cin >> t ;

	while(t--){
		cin >> n ;
		cin.ignore() ;
		init() ;

		stringstream ss ;
		string line, type ;
		int i, j ;

		int a = 0, b = 0 ;
		while(getline(cin, line) && !line.empty()){
			ss.clear() ;
			ss << line ;
			ss >> type >> i >> j ;
			
			if(type == "c")
				insert(i, j) ;
			else
				find(i) == find(j) ? a++ : b++ ;
		}

		cout << a << "," << b << endl ;
		if(t)	cout << endl ;
	}

	return 0;
}