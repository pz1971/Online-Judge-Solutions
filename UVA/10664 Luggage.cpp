#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

template<class t>
bool scan(t &n){
	 bool neg = false;
	 char ch = getchar();
	 if(ch=='-') neg = true;
	 n = 0;
	 for( ; isdigit(ch); ch = getchar())
		n = n*10 + (ch - '0');
	if(neg) n = 0-n;
	return (ch != '\n') ;
}

int dp[205], ar[22] ;
int n ;

int main(){

	int m ;
	scan(m) ;

	while(m--){
		memset(dp, 0, sizeof dp);
		n = 0 ;
		while(scan(ar[++n])) ;
		
		int sum = 0 ;
		for(int i = 1 ; i <= n; i++)
			sum += ar[i] ;
		int k = sum / 2 ;

		for(int i = 1 ; i <= n ; i++){
			for(int j = k ; j >= ar[i] ; j--){
				dp[j] = max(dp[j], dp[j - ar[i]] + ar[i]) ;
			}
		}
		int mx = dp[0] ;
		for(int i = 1 ; i <= k ; i++)
			mx = max(mx, dp[i]) ;
		
		cout << ((mx * 2 == sum) ? "YES" : "NO") << endl ;
	}

	return 0;
}