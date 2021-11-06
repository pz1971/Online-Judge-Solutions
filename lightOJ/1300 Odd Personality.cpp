#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

const int MX = 10005 ;
vector<int> g[MX], g2[MX] ;
vector<pair<int, int> > bridges ;
int id, d[MX], low[MX], d2[MX] ;

void clear(int n)
{
    id = 0 ;
    bridges.clear() ;
    for(int i = 0 ; i < n ; i++)
    {
        g[i].clear() ;
        g2[i].clear() ;
        d[i] = d2[i] = 0 ;
        low[i] = INT_MAX ;
    }
}

int dfs(int u, int par)
{
    d[u] = low[u] = ++id ;
    for(auto v : g[u])
    {
        if(v == par)
            continue ;
        if(d[v] == 0)
        {
            low[v] = dfs(v, u) ;
            if(d[u] < low[v])
                bridges.push_back(make_pair(min(u, v), max(u, v))) ;
        }
        low[u] = min(low[u], low[v]) ;
    }
    return low[u] ;
}

inline bool is_bridge(int u, int v)
{
    if(u > v)
        swap(u, v) ;
    return binary_search(bridges.begin(), bridges.end(), make_pair(u, v)) ;
}

int cnt ;
bool odd ;

void dfs2(int u, int par, int w)
{
    cnt++ ;
    d2[u] = w ;

    for(auto v : g2[u])
    {
        if(d2[v] == 0)
            dfs2(v, u, w + 1) ;
        else if((abs(d2[v] - d2[u]) + 1) % 2 != 0)
            odd = 1 ;
    }
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

        for(int i = 0 ; i < n ; i++)
        {
            if(d[i] == 0)
                dfs(i, -1) ;
        }

        sort(bridges.begin(), bridges.end()) ;

        for(int i = 0 ; i < n ; i++)
        {
            for(auto j : g[i])
            {
                if(!is_bridge(i, j))
                    g2[i].push_back(j) ;
            }
        }

        int ans = 0 ;
        for(int i = 0 ; i < n ; i++)
        {
            if(d2[i] == 0)
            {
                cnt = odd = 0 ;
                dfs2(i, -1, 1) ;
                if(odd)
                    ans += cnt ;
            }
        }

        cout<< "Case "<< tc<< ": " << ans << endl ;
    }

    return 0;
}