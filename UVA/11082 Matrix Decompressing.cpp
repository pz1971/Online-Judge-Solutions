#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int test_cases ;
    cin >> test_cases ;
    
    for(int tc = 1 ; tc <= test_cases ; tc++){
        if(tc > 1)  cout << endl ;
        cout << "Matrix " << tc << endl ;

        int r, c ;
        cin >> r >> c ;
        vector<int> RR(r), CC(c) ;
        vector<vector<int> > mat(r, vector<int> (c, 0)) ;
        
        for(auto &i : RR)    cin >> i ;
        for(auto &i : CC)    cin >> i ;
        
        for(int i = r - 1 ; i > 0 ; i--)
            RR[i] -= RR[i-1] ;
        for(int i = c - 1 ; i > 0 ; i--)
            CC[i] -= CC[i-1] ;
        
        vector<pair<int, int> > R, C ;
        for(int i = 0 ; i < r ; i++)
            R.push_back(make_pair(RR[i], i)) ;
        for(int i = 0 ; i < c ; i++)
            C.push_back(make_pair(CC[i], i)) ;

        sort(R.begin(), R.end(), greater<pair<int, int> >()) ;

        for(int i = 0 ; i < r ; i++){
            sort(C.begin(), C.end(), greater<pair<int, int> >()) ;
            int ii = R[i].second ;

            for(int j = 0 ; j < c ; j++){
                if(C[j].first == 0)   break ;
                int jj = C[j].second ;

                int x = min(20, min(R[i].first - (c - (j + 1)), C[j].first - (r - (i + 1)))) ;
                mat[ii][jj] = x ;
                R[i].first -= x ;
                C[j].first -= x ;
            }
        }

        for(auto &i : mat){
            for(auto j : i)
                cout << j << " " ;
            cout << endl ;
        }
    }

    return 0;
}