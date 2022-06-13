#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

const int MX = 2e5 + 5 ;
vector<int> g[MX] ;
int cnt[MX] ;

void dfs(int u)
{
    for(auto v : g[u])
    {
        dfs(v) ;
        cnt[u] += cnt[v] + 1 ;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n ;
    cin >> n ;
    
    for(int i = 2 ; i <= n ; i++)
    {
        int j ;
        cin >> j ;
        g[j].push_back(i) ;
    }

    dfs(1) ;
    for(int i = 1 ; i <= n ; i++)
        cout << cnt[i] << " " ;
    cout << endl ;

    return 0;
}