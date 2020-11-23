#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

const int mx = 1005 ;
int n, k; 

vector<int> g[mx], child[mx], subtree(mx), mark(mx) ;

class cmp{
public :
    bool operator () (int a, int b){
        return (subtree[a] > subtree[b]) ;
    }
} ;

int dfs(int u){
    mark[u] = 1 ;
    subtree[u] = 1 ;

    for(auto i : g[u]){
        if(!mark[i]){
            child[u].push_back(i) ;
            subtree[u] += dfs(i) ;
        }
    }

    if(child[u].size() < k){
        child[u].clear() ;
        subtree[u] = 1 ;
    }
    else if(child[u].size() == k)
        return subtree[u] ;
    
    sort(child[u].begin(), child[u].end(), cmp()) ;
    while(child[u].size() > k)
        child[u].pop_back() ;
    
    subtree[u] = 1 ;
    for(auto i : child[u])
        subtree[u] += subtree[i] ;
    return subtree[u] ;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int test_cases ;
    cin >> test_cases ;
    
    for(int tc = 1 ; tc <= test_cases ; tc++){
        cin >> n >> k ;
        for(int i = 1 ; i <= n ; i++){
            g[i].clear(), child[i].clear() ;
            subtree[i] = mark[i] = 0 ;
        }

        int u, v ;
        for(int i = 1 ; i < n ; i++){
            cin >> u >> v ;
            g[u].push_back(v) ;
            g[v].push_back(u) ;
        }

        cout<< "Case "<< tc<< ": " << dfs(1) << endl ;
    }

    return 0;
}