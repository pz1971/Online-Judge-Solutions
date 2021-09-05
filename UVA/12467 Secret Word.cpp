#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 1000000 ;
string s ;
int pi[mx] ;

void init(){
	int j = 0 ;
	pi[0] = 0 ;

	for(int i = 1 ; i < s.size() ; i++){
		if(s[i] == s[j])
			pi[i] = ++j ;
		else{
			pi[i] = 0 ;
			while(j){
				j = pi[j-1] ;
				if(s[i] == s[j]){
					pi[i] = ++j ;
					break ;
				}
			}
		}
	}
}

string kmp(){
	init() ;
	int j = 0 ;
	int ret = 0 ;

	for(int i = s.size()-1 ; i >= 0 ; i--){
		if(s[i] == s[j])
			ret = max(ret, ++j) ;
		else{
			while(j){
				j = pi[j-1] ;
				if(s[i] == s[j]){
					ret = max(ret, ++j) ;
					break ;
				}
			}
		}
	}
	string s2 = s.substr(0, ret) ;
	reverse(s2.begin(), s2.end()) ;
	return s2 ;
}

int main(){

	int t;
	cin >> t ;
	while(t--){
		cin >> s ;
		cout << kmp() << endl ;
	}

	return 0;
}