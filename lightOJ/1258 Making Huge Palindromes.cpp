#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 1000005 ;
int pi[mx] ;

void prepare_pi(const string &s){
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

int KMP(const string &s){
	string p = s ;
	reverse(p.begin(), p.end()) ;
	prepare_pi(p) ;

	int j = 0 ;
	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] == p[j])
			j++ ;
		else {
			while(j){
				j = pi[j-1] ;
				if(s[i] == p[j]){
					j++ ;
					break ;
				}
			}
		}
	}

	return s.size() + s.size() - j ;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t ;
	cin >> t ;

	string s ;
	for(int tc = 1 ; tc <= t ; tc++){
		cin >> s ;
		cout<< "Case "<< tc<< ": " << KMP(s) << endl ;
	}

	return 0;
}