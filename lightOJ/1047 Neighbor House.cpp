#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test_cases ;
    cin >> test_cases ;
    
    for(int tc = 1 ; tc <= test_cases ; tc++)
    {
        int n ;
        cin >> n ;
        int r[n + 1], g[n + 1], b[n + 1] ;

        for(int i = 1 ; i <= n ; i++)
        {
            cin >> r[i] >> g[i] >> b[i] ;
        }

        int dp[n + 1][3] ;
        memset(dp[0], 0, sizeof dp[0]) ;
        for(int i = 1 ; i <= n ; i++)
        {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + r[i] ;
            dp[i][1] = min(dp[i - 1][2], dp[i - 1][0]) + g[i] ;
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + b[i] ;
        }

        int ans = min({ dp[n][0], dp[n][1], dp[n][2] }) ;
        cout<< "Case "<< tc<< ": " << ans << endl ;
    }

    return 0;
}