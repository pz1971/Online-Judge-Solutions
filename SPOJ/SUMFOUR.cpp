#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

LL a[2503], b[2503], c[2503], d[2503] ;
LL ab[2503 * 2503], cd[2503 * 2503] ;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n ;
    cin >> n ;

    for(int i = 0 ; i < n; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i] ;
    }

    int p = 0 ;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            ab[p++] = a[i] + b[j] ;
    p = 0 ;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            cd[p++] = c[i] + d[j] ;
        
    sort(cd, cd + p) ;

    LL ans = 0 ;
    for(int i = 0 ; i < p ; i++){
        int l = lower_bound(cd, cd + p, -ab[i]) - cd ;
        int u = upper_bound(cd, cd + p, -ab[i]) - cd ;
        ans += u - l ;
    }

    cout << ans << endl ;

    return 0;
}