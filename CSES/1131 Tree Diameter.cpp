#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

int n ;
vector<vector<int> > g ;
vector<int> vis ;
int mx = 0 ;

int dfs(int u)
{
    vis[u] = 1 ;
    pair<int, int> dd {0, 0} ;

    for(auto v : g[u])
    {
        if(vis[v] > 0)
            continue;
        
        dd.second = max(dd.second, dfs(v)) ;
        if(dd.second > dd.first)
            swap(dd.first, dd.second) ;
    }

    mx = max(mx, dd.first + dd.second) ;
    return dd.first + 1 ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n ;
    g.resize(n + 1) ;
    vis.resize(n + 1) ;

    int a, b ;
    for(int i = 1 ; i < n ; i++)
    {
        cin >> a >> b ;
        g[a].push_back(b) ;
        g[b].push_back(a) ;
    }

    mx = max(mx, dfs(1) - 1) ;
    cout << mx << endl ;

    return 0;
}