#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int test_case ;
	cin >> test_case ;
	
	while(test_case--){
		int k ;
		cin >> k ;
		
		int x, mx = 0, mn = INT_MAX ;
		for(int i = 0 ; i < k ; i++){
			cin >> x ;
			mx = max(mx, x) ;
			mn = min(mn, x) ;
		}

		if(k == 1 || mx == mn)
			cout << "Better luck next time!" << endl ;
		else 
			cout << "Happy Birthday Tutu!" << endl ;
	}

	return 0;
}