#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, x ;
    cin >> n >> x ;
    vector<int> c(n) ;
    for(auto &i : c)
        cin >> i ;

    vector<int> dp(x + 1, INT_MAX) ;
    dp[0] = 0 ;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = c[i] ; j <= x ; j++)
        {
            if(dp[j - c[i]] != INT_MAX)
                dp[j] = min(dp[j], dp[j - c[i]] + 1) ;
        }
    }

    cout << (dp.back() == INT_MAX ? -1 : dp.back()) << endl ;

    return 0;
}