#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

map<string, string> par ;
map<string, int> cnt ;

string find(string a){
	if(par[a].empty()){
		par[a] = a ;
		cnt[a] = 1 ;
		return a ;
	}
	else if(par[a] == a){
		return a ;
	}

	return par[a] = find(par[a]) ;
}

void insert(string u, string v){
	string a = find(u) ;
	string b = find(v) ;

	if(a != b){
		par[b] = a ;
		cnt[a] += cnt[b] ;
	}
}

int main(){

	int t ;
	cin >> t ;

	while(t--){
		par.clear() ;
		cnt.clear() ;
		
		int f ;
		cin >> f ;

		string a, b ;
		while(f--){
			cin >> a >> b ;
			insert(a, b) ;
			cout << cnt[find(a)] << endl ;
		}
	}

	return 0;
}