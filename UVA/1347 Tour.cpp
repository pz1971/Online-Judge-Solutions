#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

int n ;
vector<pair<int, int> > points ;
double dp[1005][1005] ;

inline double distance(const pair<int, int> &a, const pair<int, int> &b)
{
    return sqrt((a.first - b.first) * (a.first - b.first) 
            + (a.second - b.second) * (a.second - b.second)) ;
}

void init()
{
    for(int i = 0 ; i <= n ; i++)
        for(int j = 0 ; j <= n ; j++)
            dp[i][j] = -1 ;
}

double func(int i, int j)
{
    if(max(i, j) >= n)
        return 0 ;
    if(dp[i][j] != -1)
        return dp[i][j] ;

    int k = max(i, j) + 1 ;
    if(k == n - 1)
    {
        return dp[i][j] = distance(points[i], points[k]) + distance(points[j], points[k]) ;
    }
    double a = func(i, k) + distance(points[j], points[k]) ;
    double b = func(k, j) + distance(points[i], points[k]) ;
    return dp[i][j] = min(a, b) ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cout << fixed << showpoint << setprecision(2) ;
    points.reserve(1005) ;

    while(cin >> n)
    {
        points.resize(n) ;
        for(auto &i : points)
            cin >> i.first >> i.second ;

        init() ;
        cout << func(0, 0) << endl ;
    }

    return 0;
}