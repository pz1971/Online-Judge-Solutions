#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

LL rec(LL n){
	return n == 0LL ? 0LL : (rec(n >> 1) + (n & 1LL)) ;
}

int main(){

	int test_case ;
	cin >> test_case ;
	
	while(test_case--){
		LL n ;
		cin >> n ;
		cout << rec(n) << endl ;
	}

	return 0;
}
