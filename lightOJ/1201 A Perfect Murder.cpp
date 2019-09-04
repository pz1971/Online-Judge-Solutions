#include<bits/stdc++.h>
#define sf(a) scanf("%d", &a)
#define sff(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define pb push_back
typedef long long ll;
using namespace std;

int cnt = 0;
int visited[1005];

bool dfs(int n, vi g[]){
    visited[n] = 1;
    bool y = 1;
    for(auto i: g[n]){
        if(!visited[i]){
            y = (y & (!dfs(i, g)));
        }
    }
    if(y)   cnt++;
    return y;
}

int main(){

    int t;
    sf(t);
    for(int tc=1; tc<=t; tc++){

        int n, m;
        getchar();
        getchar();
        sff(n, m);
        vi g[n+1];
        int a, b;
        while(m--){
            sff(a, b);
            g[a].pb(b);
            g[b].pb(a);
        }
        cnt = 0;
        for(int i=1; i<=n; i++){
            if(!visited[i])
                dfs(i, g);
        }
        printf("Case %d: %d\n", tc, cnt);
        for(int i=0; i<1005; i++)   visited[i] = 0;

    }

    return 0;
}