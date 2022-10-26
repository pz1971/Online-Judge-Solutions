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
        int n, t ;
        cin >> n >> t ;
        vector<int> ar(n) ;

        int total = 0 ;
        for(auto &i : ar)
        {
            cin >> i ;
            total += i ;
        }
        if(total < t)
        {
            cout<< "Case "<< tc<< ": " << n + 1 << " " << total + 678 << endl ;
            continue ;
        }

        vector<int> dp(t, 0) ;
        t-- ;
        dp[0] = 1 ;
        for(auto i : ar)
        {
            for(int j = t ; j - i >= 0 ; j--)
            {
                if(dp[j - i] > 0)
                    dp[j] = max(dp[j], dp[j - i] + 1) ;
            }
        }

        int pos = t ;
        for(int i = t - 1 ; i >= 0 ; i--)
        {
            if(dp[i] > dp[pos])
            {
                pos = i ;
            }
        }

        cout<< "Case "<< tc<< ": " << dp[pos] << " " << pos + 678 << endl ;
    }

    return 0;
}