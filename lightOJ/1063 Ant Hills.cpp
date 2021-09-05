#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

const int MX = 10005 ;
int id ;
vector<int> g[MX], d(MX), low(MX), is_articulation_point(MX) ;

void clear(int n)
{
    for(int i = 1 ; i <= n ; i++)
    {
        g[i].clear() ;
        d[i] = is_articulation_point[i] = 0 ;
        low[i] = INT_MAX ;
    }
    id = 0 ;
}

int dfs(int par, int u)
{
    d[u] = low[u] = ++id ;
    int child_cnt = 0 ;

    for(auto v : g[u])
    {
        if(v == par)
            continue ;
        if(d[v] == 0)
        {
            low[v] = min(low[v], dfs(u, v)) ;
            child_cnt++ ;
            if( (u == 1 and child_cnt > 1) or (u != 1 and d[u] <= low[v]) )
                is_articulation_point[u] = 1 ;
            low[u] = min(low[u], low[v]) ;
        }
        else 
        {
            low[u] = min(low[u], d[v]) ;
        }
    }
    return low[u] ;
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

        int a, b ;
        set<pair<int, int> > uniq ;
        while(m--)
        {
            cin >> a >> b ;
            if(uniq.find(make_pair(min(a, b), max(a, b))) != uniq.end())
                continue ;
            g[a].push_back(b) ;
            g[b].push_back(a) ;
            uniq.insert(make_pair(min(a, b), max(a, b))) ;
        }

        low[1] = dfs(-1, 1) ;
        cout<< "Case "<< tc<< ": " << accumulate(is_articulation_point.begin() + 1, is_articulation_point.begin() + n + 1, 0) << endl ;
    }

    return 0;
}