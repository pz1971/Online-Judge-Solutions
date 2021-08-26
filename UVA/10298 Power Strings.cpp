	#include <bits/stdc++.h>
	using   namespace  std ;
	typedef long   long LL ;

	int main(){

		ios_base::sync_with_stdio(false);
		cin.tie(0); cout.tie(0);
		
		string s ;
		while(cin >> s && s != "."){
			s = s + s ;

			int pi[s.size()] ;
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

			int ans = s.size() / 2 ;
			ans /= (s.size() - pi[s.size()-1]) ;
			cout << ans << endl ;
		}

		return 0;
	}