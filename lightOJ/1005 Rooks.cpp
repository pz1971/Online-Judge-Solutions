// each rook occupies 1 entire row and 1 entire column
// number of ways to select rows = nCk
// number of ways to permute these rows = nPk
// ans = nCk * nPk 
//     = nCk * nCk * k!
// factorial of some 'k' overflow Long Long but statement says answer will be at most 10^17
// thus such 'k' won't be given in the tests.

#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    LL ncr[31][31] ;
    LL fact[31] ;
    fact[0] = 1 ;
    memset(ncr, 0, sizeof ncr) ;
    ncr[0][0] = 1 ;

    for(int i = 1 ; i <= 30 ; i++)
    {
        fact[i] = fact[i - 1] * i ;
        for(int j = 0 ; j <= 30 ; j++)
        {
            if(j > i)
                ncr[i][j] = 0 ;
            else if(j == i or j == 0)
                ncr[i][j] = 1 ;
            else
                ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1] ;
        }
    }


    int test_cases ;
    cin >> test_cases ;
    
    for(int tc = 1 ; tc <= test_cases ; tc++)
    {
        int n, k ;
        cin >> n >> k ;
        if(k > n)
        {
            cout<< "Case "<< tc<< ": 0" << endl ;
            continue ;
        }
        LL ans = ncr[n][k] * ncr[n][k] * fact[k] ;
        cout<< "Case "<< tc<< ": " << ans << endl ;
    }

    return 0;
}