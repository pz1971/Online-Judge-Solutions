#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

int n, s ;
int m[41][21] ;
LL dp[41][21][505] ;

void clear()
{
    for(int i = 0 ; i < n + n - 1 ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            m[i][j] = -1 ;
            for(int k = 0 ; k <= s ; k++)
                dp[i][j][k] = -1 ;
        }
    }
}

int nextCol(int row, int col, int dir)
{
    if(row <= n - 2)
        return col + dir ;
    else
        return col - (dir == 0) ;
}

LL func(int row, int col, int sum)
{
    if(row >= n + n - 1 or col >= n or col < 0 or m[row][col] == -1)
        return 0 ;
    if(dp[row][col][sum] != -1)
        return dp[row][col][sum] ;
    if(m[row][col] > sum)
        return dp[row][col][sum] = 0 ;
    if(row == n + n - 2 )
        return dp[row][col][sum] = (m[row][col] == sum) ;
    return dp[row][col][sum] = 
        func(row + 1, nextCol(row, col, 0), sum - m[row][col]) +
        func(row + 1, nextCol(row, col, 1), sum - m[row][col]) ;
}

string path(int row, int col, int sum)
{
    sum = sum - m[row][col] ;
    
    if(dp[row + 1][nextCol(row, col, 0)][sum] > 0)
        return "L" + path(row + 1, nextCol(row, col, 0), sum) ;
    if(dp[row + 1][nextCol(row, col, 1)][sum] > 0)
        return "R" + path(row + 1, nextCol(row, col, 1), sum) ;

    return "" ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while(cin >> n >> s)
    {
        if(!(n|s))
            break ;
        clear() ;
        
        for(int i = 0 ; i < n ; i++)
            for(int j = i ; j < n ; j++)

                cin >> m[i][j] ;
        for(int i = 2 ; i <= n ; i++)
            for(int j = n - i ; j < n ; j++)
                cin >> m[i + n - 2][j] ;

        LL cnt = 0, x ;
        int starting = -1 ;
        for(int i = 0 ; i < n ; i++)
        {
            x = func(0, i, s) ;
            cnt += x ;
            if(x > 0 and starting == -1)
                starting = i ;
        }
        if(cnt == 0)
        {
            cout << 0 << endl << endl ;
        }
        else
        {
            cout << cnt << endl ;
            cout << starting << " " << path(0, starting, s) << endl ;
        }
    }

    return 0;
}