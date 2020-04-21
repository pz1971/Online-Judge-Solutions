#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int main(){

	int n ;
	while(cin >> n && n){
		unordered_map<LL, int> mp ;
		unordered_map<LL, int> sums ;

		vector<LL> ar(n) ;
		for(auto &i : ar){
			cin >> i ;
			mp[i] = 1 ;
		}

		sort(ar.begin(), ar.end()) ;

		for(int i = 0 ; i < n ; i++){
			for(int j = i+1 ; j < n ; j++){
				sums[ar[i] + ar[j]]++ ;
			}
		}

		bool f = false ;
		LL ans = LLONG_MIN ;
		
		for(int i = n-1 ; i >= 0 ; i--){
			for(int j = 0 ; j < n ; j++){
				if(i == j)	continue ;

				LL d = ar[i], a = ar[j] ;
				LL b_plus_c = d - a ;
				
				if(!sums.count(b_plus_c))
					continue ;
				
				int x = 0 ;
				if(mp.count(b_plus_c - d))	x++ ;
				if(mp.count(b_plus_c - a))	x++ ;
				if(d + a == b_plus_c)			x-- ;

				if(sums[b_plus_c] > x){
					ans = d ;
					f = true ;
					break;
				}
			}

			if(f)	break ;
		}

		if(f)	cout << ans << endl ;
		else 	cout << "no solution" << endl ;
	}

	return 0;
}