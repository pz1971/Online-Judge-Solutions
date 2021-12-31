#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

const int MX = 1003 ;
int n, m, id ;
vector<int> g[MX] ;
int low[MX], vis[MX] ;
vector<pair<int, int> > bridges ;

void clear()
{
    id = 0 ;
    for(int i = 0 ; i <= n ; i++)
    {
        g[i].clear() ;
        low[i] = INT_MAX ;
        vis[i] = 0 ;
    }
    bridges.clear() ;
}

void dfs(int u, int par)
{
    low[u] = vis[u] = ++id ;
    for(auto v : g[u])
    {
        if(v == par)
            continue ;
        if(!vis[v])
        {
            dfs(v, u) ;
            if(vis[u] < low[v])
                bridges.push_back(make_pair(min(u, v), max(u, v))) ;
        }
        low[u] = min(low[u], low[v]) ;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while(cin >> n >> m)
    {
        if(!(n | m))
            break ;
        clear() ;
        int u, v ;
        while(m--)
        {
            cin >> u >> v ;
            g[u].push_back(v) ;
            g[v].push_back(u) ;
        }

        for(int i = 0 ; i < n ; i++)
            if(!vis[i])
                dfs(i, -1) ;

        sort(bridges.begin(), bridges.end()) ;
        cout << bridges.size() ;
        for(int i = 0 ; i < bridges.size() ; i++)
            cout << " " << bridges[i].first << " " << bridges[i].second ;
        cout << endl ;
    }

    return 0;
}