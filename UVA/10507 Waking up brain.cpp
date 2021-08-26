#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m ;
    string s1, s2 ;

    while(cin >> n){
        set<int> nodes ;
        map<char, vector<char> > g ;

        cin >> m ;
        cin >> s1 ;
        nodes.insert(s1[0]) ;
        nodes.insert(s1[1]) ;
        nodes.insert(s1[2]) ;

        while(m--){
            cin >> s2 ;
            g[s2[0]].push_back(s2[1]) ;
            g[s2[1]].push_back(s2[0]) ;
            nodes.insert(s2[0]) ;
            nodes.insert(s2[1]) ;
        }


        map<char, int> cnt ;
        string cur = s1, nxt ;
        for(auto i : cur) cnt[i] = 3 ;
        int ans = 0 ;

        while(true){
            nxt.clear() ;
            for(auto i : cur){
                for(auto j : g[i]){
                    if(cnt[j] >= 3)
                        continue ;
                    cnt[j]++ ;
                    if(cnt[j] >= 3)
                        nxt.push_back(j) ;
                }
            }

            if(nxt.empty())
                break ;
            ans++ ;
            cur = nxt ;
        }

        for(auto i : nodes){
            if(cnt[i] < 3){
                ans = -1 ;
                break ;
            }
        }

        if(ans == -1 or nodes.size() != n)
            cout << "THIS BRAIN NEVER WAKES UP" << endl ;
        else
            cout << "WAKE UP IN, " << ans << ", YEARS" << endl ;
    }

    return 0;
}