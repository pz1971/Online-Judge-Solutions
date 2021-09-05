#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

LL cube_root(LL n){
    LL lo = 0, hi = n, m, ret = 0 ;
    while(lo <= hi){
        m = (hi + lo) >> 1 ;
        if(m * m * m > n){
            hi = m - 1 ;
        }
        else{
            ret = m ;
            lo = m + 1 ;
        }
    }
    return ret ;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string line ;
    stringstream ss ;
    double n ;

    cout << fixed << showpoint << setprecision(4) ;

    while(cin >> line){
        if(line == "0")
            break ;
        ss.clear() ;
        ss << line ;
        ss >> n ;

        LL a = cube_root(n) ;
        cout << (((a*a*a) << 1) + n) / (3.0*a*a) << endl ;
    }

    return 0;
}