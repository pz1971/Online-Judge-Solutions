#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

double value(pair<LL, LL> a){
	return (( a.first * 1.0 ) / ( a.second * 1.0 )) ;
}

int main(){

	LL L, n, d ;
	while(cin >> L >> n >> d){
		if(!(L | n | d))	break ;

		int minimum = ((d - 1) / L) + 1  ;
		pair<LL, LL> ans(minimum * L, 1) ;

		for(int i = minimum ; i <= n ; i++){
			LL lo = 1, hi = n, mid ;
			pair<LL, LL> mid_v ;

			for(int j = 0 ; j < 20 ; j++){
				if(lo > hi)	break ;

				mid = (lo + hi) >> 1 ;
				mid_v = make_pair(i * L, mid) ;

				if(value(mid_v) < (d * 1.0))
					hi = mid - 1 ;
				else{
					if(value(mid_v) < value(ans))
						ans = mid_v ;
					lo = mid + 1 ;
				}

			}
		}

		LL g = __gcd(ans.first, ans.second) ;
		cout << (ans.first / g) << "/" << (ans.second / g) << endl ;
	}

	return 0;
}