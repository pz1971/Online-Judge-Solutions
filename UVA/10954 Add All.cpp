#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n ;
    while(cin >> n and n){
        priority_queue<LL, vector<LL> , greater<LL> > pq ;
        LL a, b ;
        while(n--){
            cin >> a ;
            pq.push(a) ;
        }
        
        LL ans = 0 ;

        while(pq.size() > 1){
            a = pq.top() ;
            pq.pop() ;
            b = pq.top() ;
            pq.pop() ;
            
            ans += a + b ;
            pq.push(a + b) ;
        }

        cout << ans << endl ;
    }

    return 0;
}