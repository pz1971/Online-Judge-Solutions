#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int f(int n, int k){
	if(k == 0 || n == 1)	return -1 ;
	int ret = 1 ;
	
	k-- ;
	for(int i = 30 ; (k && i) ; i--){
		if(((1 << i ) | ret) > n)
			continue ;
		ret |= (1 << i) ;
		k-- ;
	}
	
	return ret ;
}

int main(){

	int t ;
	cin >> t ;
	while(t--){
		int n, k ;
		cin >> n >> k ;
		cout << f(n, k) << endl ;
	}

	return 0;
}