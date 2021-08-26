#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

const int mod = 10000007 ;
int a, b, c, d, e, f;
int dp[10005] ;

void fn(int n){
	dp[0] = a % mod ;
	dp[1] = b % mod ;
	dp[2] = c % mod ;
	dp[3] = d % mod ;
	dp[4] = e % mod ;
	dp[5] = f % mod ;

	for(int i = 6 ; i <= n ; i++){
		dp[i] = ( dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6] ) % mod ;
	}
}

int main() {

    int n, caseno = 0, cases;
    scanf("%d", &cases);

    while( cases-- ) {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        fn(n) ;

		printf("Case %d: %d\n", ++caseno, dp[n] % mod);
    }

    return 0;
}