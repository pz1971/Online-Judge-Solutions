#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

inline char solve(int n, int m){
	if(n <= m){
		if(n % 2 == 0)
			return 'L' ;
		else 
			return 'R' ;
	}
	else{
		if(m % 2 == 0)
			return 'U' ;
		else 
			return 'D' ;
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int test_case ;
	cin >> test_case ;
	
	while(test_case--){
		int n, m ;
		cin >> n >> m ;
		cout << solve(n, m) << endl ;
	}

	return 0;
}