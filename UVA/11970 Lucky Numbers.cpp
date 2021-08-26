#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test_cases ;
    cin >> test_cases ;
    
    for(int tc = 1 ; tc <= test_cases ; tc++){
        LL n ;
        cin >> n ;
        vector<LL> ans ;

        for(LL i = 1 ; ; i++){
            LL ii = i * i ;
            LL x = n - ii ;
            if(x <= 0LL)
                break ;
            if((x * x) % (n - x) == 0)
                ans.push_back(x) ;
        }
        reverse(ans.begin(), ans.end()) ;

        cout<< "Case "<< tc<< ":" ;
        for(auto i : ans)
            cout << " " << i ;
        cout << endl ;
    }

    return 0;
}