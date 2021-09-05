#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

const int LG = 15 ;
const int MX = (1 << 14) ;

vector<pair<int, int> > g[MX] ;
int par[MX][LG], dist[MX], level[MX] ;

void clear(int n){
    for(int i = 1 ; i <= n ; i++){
        g[i].clear() ;
        for(int j = 0 ; j < LG ; j++)
            par[i][j] = -1 ;
    }
}

void dfs(int p, int u, int l){
    level[u] = l ;
    par[u][0] = p ;

    for(auto vw : g[u]){
        if(vw.first == p)
            continue ;
        dist[vw.first] = dist[u] + vw.second ;
        dfs(u, vw.first, l + 1) ;
    }
}

void init_par(int n){
    for(int j = 1 ; j < LG ; j++){
        for(int i = 1 ; i <= n ; i++)
            par[i][j] = par[ par[i][j-1] ][j - 1] ;
    }
}

int LCA(int u, int v){
    if(level[u] < level[v])
        swap(u, v) ;

    int p, p2 ;
    for(int i = LG - 1 ; i >= 0 and level[u] != level[v] ; i--){
        p = par[u][i] ;
        if(p != -1 and level[p] >= level[v])
            u = p ;
    }
    if(u == v)
        return u ;

    for(int i = LG - 1 ; i >= 0 ; i--){
        p  = par[u][i] ;
        p2 = par[v][i] ;
        if(p != p2){
            u = p ;
            v = p2 ;
        }
    }
    return par[u][0] ;
}

int find_kth_ancestor(int u, int k){
    for(int i = LG - 1 ; i >= 0 and k ; i--){
        if((1 << i) <= k and par[u][i] != -1){
            u = par[u][i] ;
            k -= (1 << i) ;
        }
    }
    return u ;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test_cases ;
    cin >> test_cases ;
    
    for(int tc = 1 ; tc <= test_cases ; tc++){
        int n ;
        cin >> n ;
        clear(n) ;

        int a, b, c, k ;
        for(int i = 1 ; i < n ; i++){
            cin >> a >> b >> c ;
            g[a].push_back(make_pair(b, c)) ;
            g[b].push_back(make_pair(a, c)) ;
        }

        dist[1] = 0 ;
        dfs(-1, 1, 0) ;
        init_par(n) ;

        string q ;
        while(cin >> q){
            if(q == "DONE")
                break ;
            cin >> a >> b ;
            c = LCA(a, b) ;

            if(q == "DIST"){
                cout << ((dist[a] - dist[c]) + (dist[b] - dist[c])) << endl ;
            }
            else{
                cin >> k ;
                if(level[a] - level[c] + 1 >= k)
                    cout << find_kth_ancestor(a, k - 1) << endl ;
                else 
                    cout << find_kth_ancestor(b, (level[a] + level[b] - 2 * level[c] + 1 - k)) << endl ;
            }
        }

        cout << endl ;
    }

    return 0;
}