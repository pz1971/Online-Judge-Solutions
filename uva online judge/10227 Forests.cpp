#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int p, t ;
set<int> g[105] ;

void init(){
	for(int i = 1 ; i <= 105 ; i++){
		g[i].clear() ;
	}
}

int main(){

	int q ;
	cin >> q ;

	stringstream ss ;
	string line ;

	while(q--){
		cin >> p >> t ;
		cin.ignore() ;
		init() ;

		int i, j ;
		while(getline(cin , line) && !line.empty()){
			ss.clear() ;
			ss << line ;
			ss >> i >> j ;
			g[i].insert(j) ;
		}

		set<set<int>> st ;
		for(int i = 1 ; i <= p ; i++)
			st.insert(g[i]) ;
		cout << st.size() << endl ;
		st.clear() ;
		if(q)	cout << endl ;
	}

	return 0;
}