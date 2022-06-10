#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

LL powmod(LL base, LL exp, LL modulus = ((1ULL << 63) - 1ULL))
{
    base %= modulus;
    long long result = 1;
    while (exp > 0)
    {
        if (exp & 1LL) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test_cases ;
    cin >> test_cases ;
    
    for(int tc = 1 ; tc <= test_cases ; tc++)
    {
        LL n, k, m ;
        cin >> n >> k >> m ;
        LL x, sum = 0 ;
        for(int i = 0 ; i < n ; i++)
        {
            cin >> x ;
            sum += x ;
        }
        LL ans = powmod(n, k-1, m) ;
        ans = (ans * k) % m ;
        ans = (ans * sum) % m ;
        cout<< "Case "<< tc<< ": " << ans << endl ;
    }

    return 0;
}