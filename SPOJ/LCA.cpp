#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

const int _MX = 1005 ;
int n ;
int is_root[_MX], level[_MX] ;
vector<int> g[_MX] ;
int sparse_table[_MX][16] ;

void init_sparse_table(){
    for(int i = 1 ; i <= n ; i++){
        for(auto j : g[i])
            sparse_table[j][0] = i ;
    }
    for(int j = 1 ; j <= 15 ; j++){
        for(int i = 1 ; i <= n ; i++){
            if(sparse_table[i][j-1] != -1)
                sparse_table[i][j] = sparse_table[ sparse_table[i][j-1] ] [j-1 ] ;
        }
    }
}

void dfs(int u, int l){
    level[u] = l ;
    for(auto v : g[u])
        dfs(v, l + 1) ;
}

int LCA(int u, int v){
    if(level[u] < level[v])
        swap(u, v) ;
    int p, p2 ;

    for(int i = 15 ; i >= 0 and level[u] != level[v] ; i--){
        p = sparse_table[u][i] ;
        if(p != -1 and level[p] >= level[v])
            u = p ;
    }

    if(u == v)
        return u ;

    for(int i = 15 ; i >= 0 ; i--){
        p  = sparse_table[u][i] ;
        p2 = sparse_table[v][i] ;
        if(p != p2){
            u = p ;
            v = p2 ;
        }
    }

    return sparse_table[u][0] ;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test_cases ;
    cin >> test_cases ;
    
    for(int tc = 1 ; tc <= test_cases ; tc++){
        cin >> n ;
        for(int i = 1 ; i <= n ; i++){
            is_root[i] = 1 ;
            level[i] = 0 ;
            g[i].clear() ;
            for(int j = 0 ; j <= 15 ; j++)
                sparse_table[i][j] = -1 ;
        }
        
        int m, u, v ;
        for(int i = 1 ; i <= n ; i++){
            cin >> m ;
            while(m--){
                cin >> v ;
                is_root[v] = 0 ;
                g[i].push_back(v) ;
            }
        }

        int root = 1 ;
        for( ; root <= n and !is_root[root] ; root++) ;

        init_sparse_table() ;
        dfs(root, 1) ;

        int q ;
        cin >> q ;

        cout<< "Case "<< tc<< ":" << endl ;
        while(q--){
            cin >> u >> v ;
            cout << LCA(u, v) << endl ;
        }
    }

    return 0;
}