#include <bits/stdc++.h>
using namespace std ;

int ar[100005][3] ;

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;

    int t ;
    cin >> t ;

    for(int tc = 1 ; tc <= t ; tc++){
        memset(ar, 0, sizeof ar) ;

        int l, r, s ;
        cin >> l >> r >> s ;
        int x, mx = -1 ;

        while(l--){
            cin >> x;
            mx = max(mx, x) ;
            ar[x][0] = 1 ;
        }
        while(r--){
            cin >> x ;
            mx = max(mx, x) ;
            ar[x][1] = 1 ;
        }
        while(s--){
            cin >> x ;
            mx = max(mx, x) ;
            ar[x][2] = 1 ;
        }

        pair<int,int> a{0,0}, b{0,0}, c{0,0} ;

        for(int i = 0 ; i <= mx ; i++){
            if(ar[i][0] && !ar[i][1] && !ar[i][2]) {
                a.first++ ;

            }
            if(!ar[i][0] && ar[i][1] && ar[i][2])
                a.second++ ;

            if(ar[i][1] && !ar[i][0] && !ar[i][2])
                b.first++ ;
            if(!ar[i][1] && ar[i][0] && ar[i][2])
                b.second++ ;

            if(ar[i][2] && !ar[i][1] && !ar[i][0])
                c.first++ ;
            if(!ar[i][2] && ar[i][1] && ar[i][0])
                c.second++ ;
        }

        cout << "Case #"  << tc << ":"  << endl ;
        cout << a.first << " " << a.second << endl ;
        cout << b.first << " " << b.second << endl ;
        cout << c.first << " " << c.second << endl ;

    }

    return 0 ;
}