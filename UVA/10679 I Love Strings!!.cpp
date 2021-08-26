#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 100005 ;
int pi[mx] ;
string s, p ;

void prepare_pi(){
	int j = 0 ;
	pi[0] = 0 ;
	
	for(int i = 1 ; i < p.size() ; i++){
		if(p[i] == p[j])
			pi[i] = ++j ;
		else {
			pi[i] = 0 ;
			while(j){
				j = pi[j-1] ;

				if(p[i] == p[j]){
					pi[i] = ++j ;
					break ;
				}
			}
		}
	}
}

bool kmp(){
	prepare_pi() ;
	int j = 0 ;

	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] == p[j]){
			j++ ;
			if(j == p.size())
				return true ;
		}
		else{
			while(j){
				j = pi[j-1] ;
				
				if(s[i] == p[j]){
					j++ ;
					break ;
				}
			}
		}
	}

	return false ;
}

int main(){

	int k, q ;

	cin >> k ;
	while(k--){
		cin >> s ;
		cin >> q ;
		while(q--){
			cin >> p ;
			cout << "ny"[kmp()] << endl ;
		}
	}

	return 0;
}