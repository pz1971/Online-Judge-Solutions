#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

const int mx = 200005 ;

vector<int> g[mx] ;
LL val[mx] ;
int subTreeSize[mx], indx[mx], chainId[mx] ;
int parent[20][mx] ;
LL tree[mx] ;

int n, q ;

void add(int pos, int val){
    while(pos <= n){
        tree[pos - 1] += val ;
        pos += pos & (-pos) ;
    }
}
LL query(int pos){
    LL ret = 0 ;
    while(pos > 0){
        ret += tree[pos - 1] ;
        pos -= pos & (-pos) ;
    }
    return ret ;
}
LL query(int p1, int p2){
    if(p1 > p2)
        swap(p1, p2) ;
    return query(p2) - query(p1 - 1) ;
}

int dfs(int u){
    subTreeSize[u] = 1 ;
    for(auto v : g[u]){
        if(subTreeSize[v] == 0)
            subTreeSize[u] += dfs(v) ;
    }
    return subTreeSize[u] ;
}

int chain_id, seg_indx ;
void dfs2(int u, int par){
    parent[0][u] = par ;
    indx[u] = seg_indx++ ;
    chainId[u] = chain_id ;

    // this line works for BIT
    // make some changes for Segment tree
    add(indx[u], val[u]) ;

    int heaviest = 0, v = -1 ;
    for(auto i : g[u]){
        if(i == par)
            continue ;
        if(subTreeSize[i] > heaviest){
            heaviest = subTreeSize[i] ;
            v = i ;
        }
    }

    if(v != -1)
        dfs2(v, u) ;
    for(auto i : g[u]){
        if(i != par and i != v){
            chain_id++ ;
            dfs2(i, u) ;
        }
    }
}

void prepare_sparse_table(){
    for(int i = 1 ; i < 20 ; i++){
        for(int j = 1 ; j <= n ; j++)
            parent[i][j] = parent[i-1][ parent[i-1][j] ] ;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q ;

    for(int i = 1 ; i <= n ; i++)
        cin >> val[i] ;

    int a, b ;
    for(int i = 1 ; i < n ; i++){
        cin >> a >> b ;
        g[a].push_back(b) ;
        g[b].push_back(a) ;
    }

    dfs(1) ;

    chain_id = seg_indx = 1 ;
    dfs2(1, 0) ;

    prepare_sparse_table() ;

    int type, s, x ;
    while(q--){
        cin >> type >> s ;
        if(type == 1){
            cin >> x ;
            val[s] = x ;
            add(indx[s], - (query(indx[s]) - query(indx[s] - 1))) ;
            add(indx[s], x) ;
        }
        else{
            LL ans = 0 ;
            
            while(s){
                int a = s ;
                for(int i = 20 ; i >= 0 ; i--){
                    if(chainId[ parent[i][s] ] == chainId[s])
                        s = parent[i][s] ;
                }
                ans += query(indx[a], indx[s]) ;
                s = parent[0][s] ;
            }

            cout << ans << endl ;
        }
    }

    return 0;
}