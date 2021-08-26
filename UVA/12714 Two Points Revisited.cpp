#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int test_cases ;
    cin >> test_cases ;
    
    for(int tc = 1 ; tc <= test_cases ; tc++){
        int x1, y1, x2, y2, x3, y3, x4, y4 ;
        cin >> x1 >> y1 >> x2 >> y2 ;

        if(x1 > x2){
            swap(x1, x2);
            swap(y1, y2);
        }

        int dx = x2 - x1 ;
        int dy = y2 - y1 ;

        if(dy >= 0){
            x3 = 0, y3 = dx ;
            x4 = dy, y4 = 0 ;
        }
        else{
            x3 = y3 = 0 ;
            x4 = -dy, y4 = dx ;
        }

        cout<< "Case "<< tc<< ": " << x3 << " " << y3 << " " << x4 << " " << y4 << endl ;
    }

    return 0;
}