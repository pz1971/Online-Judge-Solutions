#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t ;
    cin >> t ;
    vector<int> x(t) ;
    for(auto &i : x)
        cin >> i ;
    
    int a, b, m = 10001;
    bool f ;

    for(a = 0 ; a <= 10000 ; a++){
        for(b = 0 ; b <= 10000 ; b++){
            f = true ;
            for(int i = 1 ; i < x.size() ; i++){
                if((( (x[i-1] * a + b) % m ) * a + b) % m != x[i]){
                    f = false ;
                    break ;
                }
            }
            if(f)   break ;
        }
        if(f)   break ;
    }

    for(auto i : x){
        cout << (i * a + b) % m << endl ;
    }

    return 0;
}