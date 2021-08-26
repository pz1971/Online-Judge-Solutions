#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int test_cases ;
    cin >> test_cases ;
    
    for(int tc = 1 ; tc <= test_cases ; tc++){
        LL e, p, k, r;
        cin >> e >> p >> k >> r ;
        
        LL ans ;
        if(e <= p * k)
            ans = e / p + (int) (e % p != 0) ;
        else if(r >= p * k)
            ans = -1 ;
        else{
            LL e2 = e - p * k ;
            LL x = p * k - r ;
            LL swap_count = (e2 / x) + (e2 % x != 0) ;
            e = e - (swap_count * x) ;
            ans = swap_count * k + e / p + (int) (e % p != 0) ;
        }
        cout<< "Case "<< tc<< ": " << ans << endl ;
    }

    return 0;
}