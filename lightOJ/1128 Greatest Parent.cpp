#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

const int MX = 100005 ;
int n ;
int st[20][MX], val[MX] ;

void init(){
    for(int i = 0 ; i < 20 ; i++)
        for(int j = 0 ; j < n ; j++)
            st[i][j] = -1 ;

    val[0] = 1 ;
    
    int p, s ;
    for(int i = 1 ; i < n ; i++){
        cin >> p >> s ;
        st[0][i] = p ;
        val[i] = s ;
    }

    for(int i = 1 ; i < 20 ; i++)
        for(int j = 0 ; j < n ; j++)
            st[i][j] = st[i-1][ st[i-1][j] ] ;
}

int query(int k, int v){
    for(int i = 19 ; i >= 0 ; i--){
        if(st[i][k] == -1 or val[ st[i][k] ] < v)
            continue ;
        k = st[i][k] ;
    }
    return k ;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test_cases ;
    cin >> test_cases ;
    
    for(int tc = 1 ; tc <= test_cases ; tc++){
        int q;
        cin >> n >> q ;
        init() ;

        cout<< "Case "<< tc<< ":" << endl ;
        int k, v ;
        while(q--){
            cin >> k >> v ;
            cout << query(k, v) << endl ;
        }
    }

    return 0;
}