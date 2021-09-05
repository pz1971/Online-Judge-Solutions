#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n ;
    cin >> n ;

    stack<int> s ;
    int w, h ;
    int cnt = 0 ;

    for(int i = 0 ; i < n ; i++){
        cin >> w >> h ;

        while(!s.empty() and s.top() > h)
            s.pop() ;

        if(s.empty() or s.top() < h){
            s.push(h) ;
            cnt++ ;
        }
    }

    cout << cnt << endl ;

    return 0;
}