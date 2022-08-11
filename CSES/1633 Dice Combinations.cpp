#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

const LL mod = 1e9+7 ;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n ;
    cin >> n ;

    vector<LL> dp(n + 1) ;
    dp[0] = 1 ;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= 6 ; j++)
        {
            if(i - j < 0)
                break ;
            dp[i] = (dp[i] + dp[i - j]) % mod ;
        }
    }
    cout << dp.back() << endl ;

    return 0;
}