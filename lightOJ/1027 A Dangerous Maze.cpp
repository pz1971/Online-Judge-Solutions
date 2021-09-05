/*

Tutorial:

_p -> for positive attributes
_n -> for negative attributes

E = E_p + E_n
E_p = 1/n * sum(x_p)
    = 1/n * sum(|x_p|)   ------------- (1)
E_n = 1/n * sum(|x_n + E|) ----------- (2)

from (1) and (2):
    E = 1/n * sum(|x|) + n_n/n * E
 => E = sum(|x|) / n_p

*/

#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int test_cases ;
    cin >> test_cases ;
    
    for(int tc = 1 ; tc <= test_cases ; tc++){
        int n ;
        cin >> n ;
        int x, sum = 0, np = 0 ;
        
        for(int i = 0 ; i < n ; i++){
            cin >> x ;
            if(x >= 0){
                sum += x ;
                np++ ;
            }
            else{
                sum += -x ;
            }
        }

        if(np == 0){
            cout<< "Case "<< tc<< ": inf" << endl ;
            continue ;
        }
        else{
            int g = __gcd(sum, np) ;
            sum /= g ;
            np /= g ;

            cout<< "Case "<< tc<< ": " << sum << "/" << np << endl ;
        }

    }

    return 0;
}