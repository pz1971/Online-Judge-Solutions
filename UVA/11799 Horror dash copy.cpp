#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int test_cases ;
	cin >> test_cases ;
	
	for(int tc = 1 ; tc <= test_cases ; tc++){
		int n ;
		cin >> n ;
		int x = 0, mx = 0 ;
		while(n--){
			cin >> x;
			mx = max(mx, x) ;
		}
		cout<< "Case "<< tc<< ": " << mx << endl ;
	}

	return 0;
}