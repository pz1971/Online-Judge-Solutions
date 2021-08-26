#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int c, r ;
map<string, string>	par ;
map<string, int> cnt ;

string find(string u){
	if(par[u] == u)
		return u ;
	return par[u] = find(par[u]) ;
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

	while(cin >> c >> r){
		if(!(c || r))	break ;
		par.clear() ;
		cnt.clear() ;

		string s, s2 ;
		while(c--){
			cin >> s ;
			par[s] = s ;
			cnt[s] = 1 ;
		}

		while(r--){
			cin >> s >> s2 ;
			insert(s, s2) ;
		}

		int mx = 0 ;
		for(auto i : cnt)
			mx = max(mx, i.second) ;
		cout << mx << endl ;
	}

	return 0;
}