#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int distance(int a, int b){
	if(a > b)	swap(a, b) ;
	return min(b - a, a + (10 - b)) ;
}

int main(){

	int test_case ;
	cin >> test_case ;
	
	for(int tc = 1 ; tc <= test_case ; tc++){
		int n ;
		string s, t ;
		cin >> n >> s >> t ;

		int ans = 0 ;
		for(int i = 0 ; i < n ; i++)
			ans += distance(s[i] - '0', t[i] - '0') ;
		cout<< "Case "<< tc<< ": " << ans << endl ;
	}

	return 0;
}