#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    LL n, s ;
    while(cin >> n >> s){
        vector<LL> ar(n) ;
        for(LL i = 0 ; i < n ; i++){
            cin >> ar[i] ;
        }
        
        LL ans = n ;
        bool f = false ;
        LL p1 = 0, p2 = 0 ;
        LL cur = 0 ;

        while(p1 < n){
            while(cur < s and p2 < n){
                cur += ar[p2++] ;
            }
            if(cur < s)
                break ;
            ans = min(ans, p2 - p1) ;
            if(p2 - p1 <= ans){
                f = true ;
                ans = p2 - p1 ;
            }
            cur -= ar[p1++] ;
        }

        cout << ans * f << endl ;
    }

    return 0;
}