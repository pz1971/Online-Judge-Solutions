#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, tc = 0 ;
    while(cin >> n){
        if(!n)  break ;
        int s ;
        cin >> s ;

        int p, q ;
        vector<int> g[n+1] ;
        while(cin >> p >> q){
            if(!(p | q))
                break ;
            g[p].push_back(q) ;
        }

        vector<int> vis(n+1) ;
        priority_queue<pair<int, int> > pq ;
        pq.push(make_pair(0, s)) ;

        while(!pq.empty()){
            // int w = pq.top().first ;
            int u = pq.top().second ;
            pq.pop() ;

            for(auto v : g[u]){
                if(vis[v] < vis[u] + 1){
                    vis[v] = vis[u] + 1 ;
                    pq.push(make_pair(vis[u]+1, v)) ;
                }
            }
        }

        int longest = 0, finished_at = s ;
        for(int i = 1 ; i <= n ; i++){
            if(vis[i] > longest){
                finished_at = i ;
                longest = vis[i] ;
            }
        }

        cout<< "Case "<< ++tc ;
        cout << ": The longest path from " << s << " has length " << longest << ", finishing at " << finished_at << "." ;
        cout << endl << endl ;
    }

    return 0;
}