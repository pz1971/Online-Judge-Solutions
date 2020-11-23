#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n ;
    while(cin >> n){
        if(!n)  break; 
        
        vector<int> ar(n), ar2(n) ;
        int x, y;
        
        for(int i = 0; i < n;  i++){
            cin >> x >> y;
            ar[i] = (x + y) ;
            ar2[i] = (x - y) ;
        }

        sort(ar.begin(), ar.end()) ;
        sort(ar2.begin(), ar2.end()) ;

        int ans = 0 ;
        for(int i = 0 ; i <= 10000 ; i++){
            x = lower_bound(ar.begin(), ar.end(), i) - ar.begin() ;
            y = upper_bound(ar2.begin(), ar2.end(), i) - ar2.begin() ;
            ans = max(ans, y - x) ;
        }

        cout << ans << endl ;
    }

    return 0;
}