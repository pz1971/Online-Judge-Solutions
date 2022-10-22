#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

struct Block {
    int x, y, z;

    Block() {}
    Block(int x, int y, int z)
    : x(x), y(y), z(z) {}
    
    bool operator < (Block& b) const {
        return ((x < b.x) && (y < b.y));
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, tc = 0 ;
    while(cin >> n)
    {
        if(n == 0)
            break ;

        vector<Block> blocks ;
        int x, y, z ;
        int ans = 0 ;

        for(int i = 0 ; i < n ; i++)
        {
            cin >> x >> y >> z ;
            ans = max({ans, x, y, z}) ;

            blocks.emplace_back( Block(x, y, z) ) ;
            blocks.emplace_back( Block(x, z, y) ) ;
            blocks.emplace_back( Block(y, x, z) ) ;
            blocks.emplace_back( Block(y, z, x) ) ;
            blocks.emplace_back( Block(z, x, y) ) ;
            blocks.emplace_back( Block(z, y, x) ) ;
        }

        int N = blocks.size() ;
        vector<vector<int> > dis (N, vector<int> (N, -1)) ;
        for(int i = 0 ; i < N ; i++)
        {
            for(int j = 0 ; j < N ; j++)
            {
                if(blocks[j] < blocks[i])
                    dis[i][j] = blocks[j].z ;
            }
        }

        // for(int _ = 0 ; _ < 2 ; _++)
        for(int k = 0 ; k < N ; k++)
        {
            for(int i = 0 ; i < N ; i++)
            {
                if(dis[i][k] == -1)
                    continue;
                for(int j = 0 ; j < N ; j++)
                {
                    if(dis[k][j] == -1)
                        continue;
                    
                    dis[i][j] = max(dis[i][j], dis[i][k] + dis[k][j]) ;
                }
            }
        }

        for(int i = 0 ; i < N ; i++)
        {
            for(int j = 0 ; j < N ; j++)
            {
                if(dis[i][j] != -1)
                    ans = max(ans, blocks[i].z + dis[i][j]) ;
            }
        }

        cout<< "Case "<< ++tc<< ": maximum height = " << ans << endl ;
    }

    return 0;
}