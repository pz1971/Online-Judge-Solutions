#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

int m, n ;
int dp[1005][1005] ;
int g[1005][1005] ;

map<pair<int, int> , vector<int> > edges ;
int ans ;

vector<int> path ;
bool path_found = false ;

void dfs(int r, int c)
{
    if(c == n - 1 and dp[r][c] == ans)
    {
        path_found = true ;
        for(auto i: path)
            cout << i + 1 << " " ;
        cout << r + 1 << endl ;
        return ;
    }

    path.push_back(r) ;
    sort(edges[make_pair(r, c)].begin(), edges[make_pair(r, c)].end()) ;
    
    for(auto next_row : edges[make_pair(r, c)])
    {
        if(!path_found)
            dfs(next_row, c + 1) ;
    }

    path.pop_back() ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while(cin >> m >> n)
    {
        for(int i = 0 ; i < m ; i++)
            for(int j = 0 ; j < n ; j++)
                cin >> g[i][j] ;

        edges.clear() ;
        for(int row = 0 ; row < m ; row++)
        {
            dp[row][0] = g[row][0] ;
        }

        for(int col = 1 ; col < n ; col++)
        {
            for(int row = 0 ; row < m ; row++)
            {
                dp[row][col] = min({
                    dp[(row - 1 + m) % m][col - 1],
                    dp[row][col - 1],
                    dp[(row + 1) % m][col - 1],
                }) ;

                if(dp[row][col] == dp[(row - 1 + m) % m][col - 1])
                    edges[ make_pair( (row - 1 + m) % m, col - 1 ) ].push_back(row) ;
                if(dp[row][col] == dp[row][col - 1])
                    edges[ make_pair( row, col - 1 ) ].push_back(row) ;
                if(dp[row][col] == dp[(row + 1) % m][col - 1])
                    edges[ make_pair( (row + 1) % m, col - 1 ) ].push_back(row) ;

                dp[row][col] += g[row][col] ;
            }
        }

        ans = INT_MAX ;
        for(int row = 0 ; row < m ; row++)
            ans = min(ans, dp[row][n - 1]) ;
        
        path.clear() ;
        path_found = false ;
        for(int row = 0 ; row < m and !path_found ; row++)
        {
            dfs(row, 0) ;
        }
        cout << ans << endl ;
    }

    return 0;
}