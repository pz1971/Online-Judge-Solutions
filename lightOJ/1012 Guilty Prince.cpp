#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define fastIO std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define sf(a) scanf("%d", &a)
#define sff(a, b) scanf("%d %d", &a, &b)
typedef long long ll;
using namespace std;

char g[25][25];
int dfs = 1, m[25][25];

void DFS(pair<int, int> t){

    if( g[t.first-1][t.second] == '.' && m[t.first-1][t.second] == 0 ){
        m[t.first-1][t.second] = 1;
        dfs++;
        DFS( make_pair(t.first-1, t.second) );
    }

    if( g[t.first+1][t.second] == '.' && m[t.first+1][t.second] == 0 ){
        m[t.first+1][t.second] = 1;
        dfs++;
        DFS( make_pair(t.first+1, t.second) );
    }

    if( g[t.first][t.second-1] == '.' && m[t.first][t.second-1] == 0 ){
        m[t.first][t.second-1] = 1;
        dfs++;
        DFS( make_pair(t.first, t.second-1) );
    }

    if( g[t.first][t.second+1] == '.' && m[t.first][t.second+1] == 0 ){
        m[t.first][t.second+1] = 1;
        dfs++;
        DFS( make_pair(t.first, t.second+1) );
    }

}

int main(){

    int t;
    for(int i=0; i<25; i++)
        for(int j=0; j<25; j++)
            g[i][j] = '#';
    sf(t);

    for(int tc=1; tc<=t; tc++){
        int w, h;
        sff(w, h);
        getchar();
        pair<int, int> source;

        for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++){
                g[i][j] = getchar();
                if(g[i][j] == '@'){
                    source.first = i;
                    source.second = j;
                }
            }
            g[i][w+1] = '#';
            getchar();
        }

        for(int i=1; i<=w; i++){
            g[h+1][i] = '#';
        }

        for(int i=0; i<25; i++)
            for(int j=0; j<25; j++)
                m[i][j] = 0;
        
        dfs = 1;
        DFS(source);
        
        printf("Case %d: %d\n", tc, dfs);
    }

    return 0;
}