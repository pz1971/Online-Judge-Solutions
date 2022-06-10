#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

LL n, k ;
LL dp[65][35][105] ;

LL func(LL pos, LL ones, LL mod)
{
    if(ones + ones > n or (pos - ones) * 2 > n)
        return 0 ;
    if(pos == n)
    {
        if(ones + ones == n and mod == 0)
            return 1 ;
        return 0 ;
    }
    if(dp[pos][ones][mod] != -1)
        return dp[pos][ones][mod] ;

    LL ret = 0 ;
    if(ones + ones < n)
        ret += func(pos + 1, ones + 1, (mod * 2LL + 1) % k) ;
    if(pos > 0)
        if((pos - ones) * 2 < n)
            ret += func(pos + 1, ones, (mod * 2) % k) ;

    return dp[pos][ones][mod] = ret ;
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
        cin >> n >> k ;
        if(n % 2 != 0 or k == 0)
        {
            cout<< "Case "<< tc<< ": 0" << endl ;
            continue ;
        }
        cout<< "Case "<< tc<< ": " << func(0, 0, 0) << endl ;
    }

    return 0;
}