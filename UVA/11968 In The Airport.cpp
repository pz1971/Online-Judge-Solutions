#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test_cases ;
    cin >> test_cases ;
    
    for(int tc = 1 ; tc <= test_cases ; tc++){
        LL n, m, k ;
        cin >> n >> m >> k ;
        vector<LL> ar(n) ;
        LL sum = 0 ;
        for(auto &i : ar){
            cin >> i ;
            sum += i ;
        }
        double avg = sum / (double) n ;

        int p = 0 ;
        for(int i = 0 ; i < m ; i++){
            if(abs(ar[i] - avg) < abs(ar[p] - avg) or (abs(ar[i] - avg) == abs(ar[p] - avg) and ar[i] < ar[p]))
                p = i ;
        }
        int p2 = m ;
        for(int i = m ; i < m + k ; i++){
            if(abs(ar[i] - avg) < abs(ar[p2] - avg) or (abs(ar[i] - avg) == abs(ar[p2] - avg) and ar[i] < ar[p2]))
                p2 = i ;
        }
        cout<< "Case #"<< tc<< ": " << ar[p] << " " << ar[p2] << endl ;
    }

    return 0;
}