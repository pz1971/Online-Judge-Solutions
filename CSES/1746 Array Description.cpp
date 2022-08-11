#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

const LL mod = 1e9+7 ;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m ;
    cin >> n >> m ;
    vector<int> ar(n) ;
    for(auto &i : ar)
        cin >> i ;
    
    vector<vector<LL> > dp(n, vector<LL> (m + 1)) ;

    if(ar[0] == 0)
    {
        for(int i = 1 ; i <= m ; i++)
            dp[0][i] = 1 ;
    }
    else
        dp[0][ar[0]] = 1 ;
    
    for(int i = 1 ; i < n ; i++)
    {
        if(ar[i] == 0)
        {
            for(int j = 1 ; j <= m ; j++)
            {
                for(int k = max(1, j - 1) ; k <= min(m, j + 1) ; k++)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod ;
                }
            }
        }
        else
        {
            for(int j = max(1, ar[i] - 1) ; j <= min(m, ar[i] + 1) ; j++)
                dp[i][ar[i]] = (dp[i][ar[i]] + dp[i - 1][j]) % mod ;
        }
    }

    LL ans = 0 ;
    for(auto i : dp.back())
        ans = (ans + i) % mod ;
    cout << ans << endl ;

    return 0;
}