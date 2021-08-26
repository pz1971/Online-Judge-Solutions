#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const LL mod = 1e9 + 7 ;

// formula: n*(n+1)*(n+2)/3
LL func(LL n){
	LL ret = 1LL ;
	ret = ( ret * ((n % 3) ? n : n / 3) ) % mod ;
	ret = ( ret * ((++n % 3) ? n : n / 3) ) % mod ;
	ret = ( ret * ((++n % 3) ? n : n / 3) ) % mod ;
	return ret ;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t ;
	cin >> t ;
	
	LL n ;
	for(int tc = 1 ; tc <= t ; tc++){
		cin >> n ;
		cout<< "Case "<< tc<< ": " << func(n) << endl ;
	}

	return 0;
}