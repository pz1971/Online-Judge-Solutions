#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

vector<LL> ar1, ar2, ar3 ;

void func(int l, int r, bool f, LL cur){
    if(l > r){
        if(f)   ar2.push_back(cur) ;
        else    ar3.push_back(cur) ;
    }
    else{
        func(l + 1, r, f, cur) ;
        func(l + 1, r, f, cur + ar1[l]) ;
        func(l + 1, r, f, cur + ar1[l] + ar1[l]) ;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int test_cases ;
    cin >> test_cases ;
    
    for(int tc = 1 ; tc <= test_cases ; tc++){
        LL n, k ;
        cin >> n >> k ;

        ar1.resize(n) ;
        ar2.clear() ;
        ar3.clear() ;

        for(auto &i : ar1)
            cin >> i ;
        
        func(0, n / 2, 0, 0LL) ;
        func((n / 2) + 1, n - 1, 1, 0LL) ;

        sort(ar2.begin(), ar2.end()) ;
        sort(ar3.begin(), ar3.end()) ;
        
        bool f = false ;

        for(auto i : ar2){
            if(i > k) break ;
            if(i == k || binary_search(ar3.begin(), ar3.end(), k - i)){
                f = true ; 
                break ;
            }
        }

        cout<< "Case "<< tc<< ": " << (f ? "Yes" : "No") << endl ;
    }

    return 0;
}