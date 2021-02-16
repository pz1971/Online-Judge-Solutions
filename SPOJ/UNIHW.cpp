#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

class cmp{
public:
    bool operator () (pair<int, int> a, pair<int, int> b){
        return (
            (a.first > b.first) or
            (a.first == b.first and a.second < b.second)
        ) ;
    }
} ;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int test_cases ;
    cin >> test_cases ;
    
    for(int tc = 1 ; tc <= test_cases ; tc++){
        int n, a ;
        cin >> n ;
        string ans(n, '0') ;

        vector<pair<int, int> > pos, neg, zero ;
        for(int i = 0 ; i < n ; i++){
            cin >> a ;
            if(a > 0)
                pos.push_back(make_pair(a, i)) ;
            else if(a < 0)
                neg.push_back(make_pair(-a, i)) ;
            else 
                zero.push_back(make_pair(0, i)) ;
        }

        sort(pos.begin(), pos.end(), cmp()) ;
        sort(neg.begin(), neg.end(), cmp()) ;

        if(!neg.empty()){
            if(neg.size() == 1){
                if(pos.empty()){
                    if(zero.empty()){
                        ans[neg[0].second] = '1' ;
                    }
                    else{
                        ans[zero[0].second] = '1' ;
                    }
                }
                else{
                    if(pos[0].first == 1){
                        ans[pos[0].second] = '1' ;
                    }
                    else{
                        for(auto &i : pos){
                            if(i.first == 1)
                                break ;
                            ans[i.second] = '1' ;
                        }
                    }
                }
            }
            else{
                if(pos.empty()){
                    ans[neg[0].second] = ans[neg[1].second] = '1' ;
                    for(int i = 3 ; i < neg.size() ; i += 2){
                        if(neg[i-1].first == 1)
                            break ;
                        ans[neg[i-1].second] = ans[neg[i].second] = '1' ;
                    }
                }
                else{
                    bool f = false ;
                    for(auto &i : pos){
                        if(i.first == 1)
                            break ;
                        f = true ;
                        ans[i.second] = '1' ;
                    }
                    for(int i = 1 ; i < neg.size() ; i += 2){
                        if(neg[i-1].first == 1)
                            break ;
                        f = true ;
                        ans[neg[i-1].second] = ans[neg[i].second] = '1' ;
                    }
                    
                    if(!f){
                        ans[pos[0].second] = '1' ;
                    }
                }
            }
        }
        else{
            if(pos.empty()){
                ans[0] = '1' ;
            }
            else{
                if(pos[0].first == 1){
                    ans[pos[0].second] = '1' ;
                }
                else{
                    for(auto &i : pos){
                        if(i.first == 1)
                            break ;
                        ans[i.second] = '1' ;
                    }
                }
            }
        }

        cout<< "Case "<< tc<< ": " << ans << endl ;
    }

    return 0;
}