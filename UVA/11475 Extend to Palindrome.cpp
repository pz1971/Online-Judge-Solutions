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

string KMP(const string &s){
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

	string s2 = s.substr(0, s.size()-j) ;
	reverse(s2.begin(), s2.end()) ;

	return s + s2 ;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	string s ;
	while(cin >> s){
		cout << KMP(s) << endl ;
	}

	return 0;
}