#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

LL func(LL n)
{
    return n - (LL)sqrt(n) - (LL)sqrt(n / 2) ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test_cases ;
    cin >> test_cases ;
    
    for(int tc = 1 ; tc <= test_cases ; tc++)
    {
        LL n ;
        cin >> n ;
        cout<< "Case "<< tc<< ": " << func(n) << endl ;
    }

    return 0;
}