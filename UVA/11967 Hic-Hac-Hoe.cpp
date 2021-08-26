#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test_cases ;
    cin >> test_cases ;
    
    for(int tc = 1 ; tc <= test_cases ; tc++){
        int n, k ;
        cin >> n >> k ;

        set<pair<int, int> > s1, s2 ;
        vector<pair<int, int> > arr ;
        int x, y ;
        bool cross = 0, nought = 0 ;

        for(int i = 0 ; i < n ; i++){
            cin >> x >> y ;
            arr.emplace_back(make_pair(x, y)) ;
            if(i % 2 == 0)
                s1.insert(make_pair(x, y)) ;
            else 
                s2.insert(make_pair(x, y)) ;
        }

        vector<pair<int, int> > ar(k) ;

        for(int p = 0 ; p < n ; p++){
            if(cross and nought)
                break ;
            if((p % 2 == 0 and cross) or (p % 2 == 1 and nought))
                continue ;
            auto &s = (p % 2 == 0 ? s1 : s2) ;

            x = arr[p].first, y = arr[p].second ;
            bool f = false ;

            for(int i = 0 ; i < k ; i++){
                ar[i].first = x - k + i ;
                ar[i].second = y ;
            }
            for(int i = 0 ; i < k ; i++){
                for(auto &j : ar)
                    j.first++ ;
                f = true ;
                for(auto &j : ar){
                    if(s.find(j) == s.end()){
                        f = false ;
                        break ;
                    }
                }
                if(f)
                    goto bottom ;
            }

            for(int i = 0 ; i < k ; i++){
                ar[i].first = x ;
                ar[i].second = y - k + i ;
            }
            for(int i = 0 ; i < k ; i++){
                for(auto &j : ar)
                    j.second++ ;
                f = true ;
                for(auto &j : ar){
                    if(s.find(j) == s.end()){
                        f = false ;
                        break ;
                    }
                }
                if(f)
                    goto bottom ;
            }

            for(int i = 0 ; i < k ; i++){
                ar[i].first = x - k + i ;
                ar[i].second = y - k + i ;
            }
            for(int i = 0 ; i < k ; i++){
                for(auto &j : ar)
                    j.first++, j.second++ ;
                f = true ;
                for(auto &j : ar){
                    if(s.find(j) == s.end()){
                        f = false ;
                        break ;
                    }
                }
                if(f)
                    goto bottom ;
            }

            for(int i = 0 ; i < k ; i++){
                ar[i].first = x - k + i ;
                ar[i].second = y + k - i ;
            }
            for(int i = 0 ; i < k ; i++){
                for(auto &j : ar)
                    j.first++, j.second-- ;
                f = true ;
                for(auto &j : ar){
                    if(s.find(j) == s.end()){
                        f = false ;
                        break ;
                    }
                }
                if(f)
                    goto bottom ;
            }

            bottom:
                if(f){
                    if(p % 2 == 0)
                        cross = true ;
                    else 
                        nought = true ;
                }
        }

        if(cross & nought)
            cout<< "Case "<< tc<< ": error" << endl ;
        else if(!(cross | nought))
            cout<< "Case "<< tc<< ": none" << endl ;
        else if(cross)
            cout<< "Case "<< tc<< ": crosses" << endl ;
        else 
            cout<< "Case "<< tc<< ": noughts" << endl ;
    }

    return 0;
}