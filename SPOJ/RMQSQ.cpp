#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

const int _MX = 1e5 + 5 ;

int n; 
int ar[_MX] ;
int st[20][_MX] ;   // sparse table

void init(){
    for(int i = 0 ; i < n ; i++)
        st[0][i] = ar[i] ;
    
    for(int i = 1 ; i < 20 ; i++){
        for(int j = 0 ; j + (1 << i) <= n ; j++)
            st[i][j] = min(st[i-1][j], st[i-1][j + (1 << (i - 1))]) ;
    }
}

int query(int lo, int hi){
    int sz = hi - lo + 1 ;
    int ret = INT_MAX ;
    int cnt = 0 ;

    while(sz){
        if(sz & 1){
            ret = min(ret, st[cnt][lo]) ;
            lo += (1 << cnt) ;
        }
        cnt++ ;
        sz >>= 1 ;
    }
    return ret ;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;

    for(int i = 0 ; i < n; i++){
        cin >> ar[i] ;
    }
    init() ;
    
    int q ;
    cin >> q ;

    int i, j ;
    while(q--){
        cin >> i >> j ;
        cout << query(i, j) << endl ;
    }

    return 0;
}