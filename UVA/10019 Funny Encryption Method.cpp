#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

int func1(int n){
    int ret = 0 ;
    while(n){
        ret += n % 2 ;
        n /= 2 ;
    }
    return ret ;
}

int func2(int n){
    int ret = 0 ;
    while(n){
        ret += func1(n % 10) ;
        n /= 10 ;
    }
    return ret ;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int test_cases ;
    cin >> test_cases ;
    
    for(int tc = 1 ; tc <= test_cases ; tc++){
        int m ;
        cin >> m ;
        cout << func1(m) << " " << func2(m) << endl ;
    }

    return 0;
}