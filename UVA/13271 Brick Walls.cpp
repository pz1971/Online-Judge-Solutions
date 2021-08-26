#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    while(true){
        LL sr, sc, dr, dc ;
        cin >> sr >> sc >> dr >> dc ;
        if(!(sr | sc | dr | dc))
            break ;
        
        if(sr >= dr){
            swap(sr,dr) ;
            swap(sc,dc) ;
        }

        LL dx = abs(dr - sr), dy = abs(dc - sc) ;

        if(dy >= dx)
            cout << dx + dy << endl ;
        else{
            LL ans = 0 ;
            if((sr + sc) % 2 == 0)
                ans = 2 * dx - 1 ;
            else
                ans = 2 * dx ;

            ans += ((dc + dr) % 2 == 0) ;
            cout << ans << endl ;
        }
    }

    return 0;
}