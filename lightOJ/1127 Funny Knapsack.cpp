#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

vector<LL> ar1, ar2, ar3 ;

void generate(int l, int r, bool f, LL cur){
    if(l > r){
        if(f)   ar2.push_back(cur) ;
        else    ar3.push_back(cur) ;
    }
    else{
        generate(l + 1, r, f, cur) ;
        generate(l + 1, r, f, cur + ar1[l]) ;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int test_cases ;
    cin >> test_cases ;
    
    for(int tc = 1 ; tc <= test_cases ; tc++){
        LL n, w ;
        cin >> n >> w ;
        
        ar1.resize(n) ;
        ar2.clear() ;
        ar3.clear() ;

        for(auto &i : ar1)
            cin >> i ;
        
        generate(0, n / 2, 0, 0LL) ;
        generate(n / 2 + 1, n - 1, 1, 0LL) ;

        sort(ar3.begin(), ar3.end()) ;
        if(ar3.empty())
            ar3.push_back(0) ;
        LL ans = 0 ;
        
        for(auto i : ar2){
            if(i > w)   continue ;
            int p = upper_bound(ar3.begin(), ar3.end(), w - i) - ar3.begin() ;
            ans += p ;
        }

        cout<< "Case "<< tc<< ": " << ans << endl ;
    }

    return 0;
}