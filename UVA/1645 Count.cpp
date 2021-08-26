// iterative

#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const LL mod = 1e9 + 7 ;

LL dp[1005] ;

int main(){

	dp[0] = dp[1] = 1 ;
	
	for(int i = 2 ; i < 1004 ; i++){
		for(int j = 1 ; j < i ; j++){
			if((i - j - 1) % j == 0)
				dp[i] = (dp[i] + dp[j]) % mod ;
		}
	}

	int n, tc = 0 ;

	while(cin >> n)
		cout<< "Case "<< ++tc<< ": " << dp[n] << endl ;

	return 0;
}

// recursive

// #include <bits/stdc++.h>
// using   namespace  std ;
// typedef long   long LL ;

// const LL mod = 1e9 + 7 ;

// LL dp[1005] ;

// LL func(int n){
// 	if(dp[n])
// 		return dp[n] ;
	
// 	for(int i = 1 ; i < n ; i++){
// 		if((n - i - 1) % i == 0)
// 			dp[n] = (dp[n] + func(i)) % mod ;
// 	}

// 	return dp[n] ;
// }

// int main(){

// 	dp[1] = dp[2] = 1 ;
	
// 	int n ;
// 	int tc = 0 ;

// 	while(cin >> n)
// 		cout<< "Case "<< ++tc<< ": " << func(n) << endl ;
	

// 	return 0;
// }
