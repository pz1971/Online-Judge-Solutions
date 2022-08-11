#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

const LL mod = 1e9 + 7 ;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, x ;
    cin >> n >> x ;
    vector<int> c(n) ;
    for(auto &i : c)
        cin >> i ;
    
    vector<LL> dp(x + 1) ;
    dp[0] = 1 ;
    for(int j = 1 ; j <= x ; j++)
    {
        for(int i = 0 ; i < n ; i++)
            if(j >= c[i])
                dp[j] = (dp[j] + dp[j - c[i]]) % mod ;
    }
    cout << dp.back() << endl ;

    return 0;
}