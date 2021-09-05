#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int test_cases ;
	cin >> test_cases ;
	
	for(int tc = 1 ; tc <= test_cases ; tc++){
		LL x, y ;
		cin >> x >> y ;
		LL X = x ;
		x = x + 2 - y ;

		if(x < 0LL){
			cout << "Impossible" << endl ;
			continue ;
		}
		if(x == 0LL){
			cout << ++X << endl ;
			continue ;
		}
		if(y == 2LL){
			cout << 1 << endl ;
			continue ;
		}

		bool f = false ;
		LL ans = 0LL ;
		for(LL i = 1 ; i * i <= x ; i++){
			if(x % i == 0 && (X % i + 2LL == y)){
				ans = i ;
				f = true ;
				break ;
			}
			else if(x % i == 0 && (X % (x/i) + 2LL == y)){
				ans = x/i ;
				f = true ;
			}
		}

		if(f)	cout << ans << endl ;
		else	cout << "Impossible" << endl ;
	}

	return 0;
}