#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

int k, l ;
int dp[1000007] ;

int func(int n){
    if(n == 1 or n == k or n == l)
        return 1 ;  // win
    if(n == 0)
        return 2 ;  // lose

    if(dp[n])
        return dp[n] ;
    
    if(n >= l and func(n - l) == 2)
        return dp[n] = 1 ;
    if(n >= k and func(n - k) == 2)
        return dp[n] = 1 ;
    if(n >= 1 and func(n - 1) == 2)
        return dp[n] = 1 ;

    return dp[n] = 2 ;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int m, n ;
    cin >> k >> l >> m ;
    
    while(m--){
        cin >> n ;
        cout << "AB"[func(n) - 1] ;
    }
    cout << endl ;

    return 0;
}