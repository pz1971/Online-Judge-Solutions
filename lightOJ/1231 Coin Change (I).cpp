#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

const LL mod = 100000007 ;

int n, k ;
int a[51], c[51] ;
LL dp[51][1001] ; 

LL func(int coin, int sum)
{
    if(sum == 0)
        return 1 ;
    if(coin >= n)
        return 0 ;
    if(dp[coin][sum] != -1)
        return dp[coin][sum] ;
    
    LL ret = 0 ;
    
    for(int i = 0 ; i <= c[coin] and sum - i * a[coin] >= 0 ; i++)
        ret = (ret + func(coin + 1, sum - i * a[coin])) % mod ;

    return dp[coin][sum] = ret ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test_cases ;
    cin >> test_cases ;
    
    for(int tc = 1 ; tc <= test_cases ; tc++)
    {
        memset(dp, -1, sizeof dp) ;
        dp[0][0] = 1 ;
        
        cin >> n >> k ;
        for(int i = 0 ; i < n ; i++)
            cin >> a[i] ;
        for(int i = 0 ; i < n ; i++)
            cin >> c[i] ;

        auto ans = func(0, k) ;
        cout<< "Case "<< tc<< ": " << ans << endl ;
    }

    return 0;
}