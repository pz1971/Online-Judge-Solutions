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

        vector<vector<LL> > ar(2 * n - 1) ;
        for(int i = 0 ; i < n ; i++)
        {
            ar[i].resize(i + 1) ;
            for(auto &j : ar[i])
                cin >> j ;
        }
        int sz = n - 1 ;
        for(int i = n ; i < ar.size() ; i++)
        {
            ar[i].resize(sz--) ;
            for(auto &j : ar[i])
                cin >> j ;
        }
        
        for(int i = 1 ; i < n ; i++)
        {
            ar[i][0] += ar[i - 1][0] ;
            for(int j = 1 ; j < i ; j++)
            {
                ar[i][j] += max(ar[i-1][j-1], ar[i-1][j]) ;
            }
            ar[i][i] += ar[i - 1][i - 1] ;
        }
        sz = n - 1 ;
        for(int i = n ; i < ar.size() ; i++)
        {
            for(int j = 0 ; j < sz ; j++)
            {
                ar[i][j] += max(ar[i-1][j], ar[i-1][j+1]) ;
            }
            sz-- ;
        }
        cout<< "Case "<< tc<< ": "<< ar.back().back() << endl ;
    }

    return 0;
}