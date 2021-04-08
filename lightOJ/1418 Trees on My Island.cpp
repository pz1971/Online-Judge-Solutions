/*
    Pick's theorem:
        A = i + b/2 - 1
    =>  i = A - b/2 + 1
    =>  i = (2A - b)/2 + 1
*/

#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

LL n, x[10005], y[10005] ;

LL calc(){
    LL A_times_2 = 0, b = 0 ;
    LL dx, dy, g ;
    for(int i = 0 ; i < n; i++){
        A_times_2 += x[i] * y[(i + 1) % n] ;
        A_times_2 -= y[i] * x[(i + 1) % n] ;

        dx = abs(x[i] - x[(i + 1) % n]) ;
        dy = abs(y[i] - y[(i + 1) % n]) ;
        g = __gcd(dx, dy) ;

        b += g ;
    }
    return ((abs(A_times_2) - b) >> 1) + 1LL ;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test_cases ;
    cin >> test_cases ;
    
    for(int tc = 1 ; tc <= test_cases ; tc++){
        cin >> n ;
        for(int i = 0 ; i < n ; i++)
            cin >> x[i] >> y[i] ;
        cout<< "Case "<< tc<< ": " << calc() << endl ;
    }

    return 0;
}