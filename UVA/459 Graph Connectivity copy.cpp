#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int n, par[26] ;
void reset(){
	for(int i = 1 ; i <= n;  i++)
		par[i] = i ;
}

int find(int u){
	if(par[u] == u)
		return u ;
	return par[u] = find(par[u]) ;
}

void set_union(int a, int b){
	int u = find(a) ;
	int v = find(b) ;

	if(u != v)
		par[u] = v ;
}

int main(){

	bool f = 0 ;
	int t ;
	string str ;

	cin >> t ;
	cin.ignore() ;
	getline(cin, str) ;

	while(t--){
		getline(cin, str) ;
		n = str[0] - 'A' + 1 ;
		reset() ;

		while(true){
			getline(cin, str) ;
			if(str.empty()){
				break;
			}

			set_union(str[0] - 'A' + 1, str[1] - 'A' + 1) ;
		}

		map<int,int> mp ;
		for(int i = 1 ; i <= n; i++)
			mp[find(i)] = 1 ;

		if(f)	cout << endl ;
		else 	f = 1 ;
		
		cout << mp.size() << endl ;
	}

	return 0;
}