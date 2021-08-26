#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

LL calc(const vector<int> &h, const vector<int> &c, int height){
    if(height < 0)
        return LLONG_MAX ;
    LL ret = 0 ;
    for(int i = 0 ; i < h.size() ; i++)
        ret += (LL) abs(h[i] - height) * (LL) c[i] ;
    return ret ;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test_cases ;
    cin >> test_cases ;
    
    for(int tc = 1 ; tc <= test_cases ; tc++){
        int n ;
        cin >> n ;
        vector<int> h(n), c(n) ;

        int hi = 0 ;

        for(auto &i : h){
            cin >> i ;
            hi = max(hi, i) ;
        }
        for(auto &i : c)
            cin >> i ;

        int lo = 0, mid ;
        LL ans = LLONG_MAX ;

        while(lo <= hi){
            mid = (hi + lo) >> 1 ;
            LL bm = calc(h, c, mid - 1) ;
            LL m = calc(h, c, mid) ;
            LL am = calc(h, c, mid + 1) ;

            ans = min(ans, m) ;
            if(bm <= m)
                hi = mid - 1 ;
            else if(am <= m)
                lo = mid + 1 ;
            else
                break ;
        }
        cout << ans << endl ;
    }

    return 0;
}