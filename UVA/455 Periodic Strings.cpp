#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int pi[200] ;

int main(){

	int t ;
	cin >> t ;

	while(t--){
		string s ;
		cin >> s ;
		s = s + s ;
		
		memset(pi, 0, sizeof pi);
		int j = 0 ;
		
		for(int i = 1 ; i < s.size() ; i++){
			if(s[i] == s[j])
				pi[i] = ++j ;
			else{
				while(j){
					j = pi[j-1] ;
					if(s[i] == s[j]){
						pi[i] = ++j ;
						break ;
					}
				}
			}
		}

		cout << s.size() - pi[s.size()-1] << endl ;
		if(t)	cout << endl ;
	}

	return 0;
}