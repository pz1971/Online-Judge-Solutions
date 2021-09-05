#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n ;
    while(cin >> n){
        if(!n)  break ;
        if(n == 1){
            cout << 1 << endl ;
            continue ;
        }
        
        queue<pair<string, int> > q ; // m, remainder
        q.push(make_pair("1", 1 % n)) ;
        set<int> st ;
        st.insert(1 % n) ;
        string s ;
        int r, r2 ;
        
        while(!q.empty()){
            s = q.front().first ;
            r = q.front().second ;
            q.pop() ;
            
            for(int i = 0 ; i <= 1 ; i++){
                r2 = (r * 10 + i) % n ;
                
                if(st.find(r2) == st.end()){
                    s.push_back("01"[i]) ;

                    if(r2 == 0){
                        cout << s << endl ;
                        goto bottom ;
                    }
                    
                    q.push(make_pair(s, r2)) ;
                    st.insert(r2) ;
                    s.pop_back() ;
                }
            }
        }

        bottom:
            continue ;
    }

    return 0;
}