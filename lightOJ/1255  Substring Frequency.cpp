#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 1000005 ;
string s, p ;
int pi[mx] ;

void prepare_pi(){
	int j = 0 ;
	pi[0] = 0 ;
	
	for(int i = 1 ; i < p.size() ; i++){
		if(p[i] == p[j])
			pi[i] = ++j ;
		else{
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

int kmp(){
	prepare_pi() ;
	int j = 0, cnt = 0 ;

	for(int i = 0 ; i < s.size() ; i++){
		while(j > 0 && s[i] != p[j])
			j = pi[j-1] ;
		
		if(++j == p.size()){
			cnt++ ;
			j = pi[j-1] ;
		}
	}

	return cnt ;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t ;
	cin >> t ;

	for(int tc = 1 ; tc <= t ; tc++){
		cin >> s >> p ;
		cout<< "Case "<< tc<< ": " << kmp() << endl ;
	}

	return 0;
}