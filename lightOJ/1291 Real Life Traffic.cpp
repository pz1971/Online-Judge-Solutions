// connected components can be considered as a single node 
// leaf = number of leaf nodes in the compressed graph formed with bridges and these components
// ans = (leaf + 1) / 2
// ** root node needs extra attention

#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

const int MX = 10005 ;
vector<int> g[MX] ;
int d[MX], low[MX], flag[MX] ;
int id ;
vector<pair<int, int> > bridges ;

void clear(int n)
{
    id = 0 ;
    bridges.clear() ;
    for(int i = 0 ; i < n ; i++)
    {
        g[i].clear() ;
        d[i] = flag[i] = 0 ;
        low[i] = INT_MAX ;
    }
}

// to find bridges
int dfs(int par, int u)
{
    d[u] = low[u] = ++id ;

    for(auto v : g[u])
    {
        if(v == par)
            continue ;
        if(d[v] == 0)
        {
            low[v] = min(low[v], dfs(u, v)) ;
            if(d[u] < low[v])
                bridges.push_back(make_pair(min(u, v), max(u, v))) ;
            low[u] = min(low[u], low[v]) ;
        }
        else 
        {
            low[u] = min(low[u], d[v]) ;
        }
    }
    return low[u] ;
}

inline bool is_bridge(int u, int v)
{
    return binary_search(bridges.begin(), bridges.end(), make_pair(min(u, v), max(u, v))) ;
}

// to find leaf nodes in compressed graph
int dfs2(int u)
{
    flag[u] = 1 ;
    int ret = 0 ;
    int b = 0 ;
    
    for(auto v : g[u])
    {
        if(flag[v])
            continue ;
        int temp = dfs2(v) ;
        if(is_bridge(u, v))
        {
            b++ ;
            ret += max(1, temp) ;
        }
        else
        {
            b += temp ;
            ret += temp ;
        }
    }

    // speacial case for root node (0)
    if(u == 0 and b == 1)
        ret++ ;

    return ret ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test_cases ;
    cin >> test_cases ;
    
    for(int tc = 1 ; tc <= test_cases ; tc++)
    {
        int n, m ;
        cin >> n >> m ;
        clear(n) ;
        int u, v ;
        while(m--)
        {
            cin >> u >> v ;
            g[u].push_back(v) ;
            g[v].push_back(u) ;
        }

        dfs(-1, 0) ;
        sort(bridges.begin(), bridges.end()) ;

        int total_leaf = dfs2(0) ;
        int ans = (total_leaf + 1) / 2 ;
        cout<< "Case "<< tc<< ": " << ans << endl ;
    }

    return 0;
}