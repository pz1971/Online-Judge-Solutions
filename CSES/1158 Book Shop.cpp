#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, x ;
    cin >> n >> x ;
    vector<int> h(n) ;
    for(auto &i : h)
        cin >> i ;
    vector<int> s(n) ;
    for(auto &i : s)
        cin >> i ;
    
    vector<int> dp(x + 1) ;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = x ; j >= h[i] ; j--)
        {
            dp[j] = max(dp[j], dp[j - h[i]] + s[i]) ;
        }
    }
    int ans = *max_element(dp.begin(), dp.end()) ;
    cout << ans << endl ;

    return 0;
}