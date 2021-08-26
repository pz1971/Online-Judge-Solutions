#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define fastIO std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define sf(a) scanf("%d", &a)
#define sff(a, b) scanf("%d %d", &a, &b)
typedef long long ll;
using namespace std;

map<int, int> level;
void bfs(int s, map<int, vi> g){
    queue<int> q;
    q.push(s);
    level[s] = 0;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(int i=0; i < g[t].size(); i++){
            if(!level.count( g[t][i] )){
                q.push( g[t][i] );
                level[ g[t][i] ] = level[t] + 1;
            }
        }
    }
}

int main(){

    int n, tc{};
//    freopen("output.txt", "w", stdout);
    while(sf(n)!=EOF && n){
        map<int, vi> g;
        int a, b;
        for(int i=0; i<n; i++){
            sff(a, b);
            g[a].pb(b);
            g[b].pb(a);
        }
        while(sff(a, b)!=EOF){
            if(a==0 && b==0)    break;
            level.clear();
            bfs(a, g);
            int cnt = 0;
            for(auto i: level){
                if(i.second > b)    cnt++;
            }
            cnt += (g.size() - level.size());
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++tc, cnt, a, b);
        }
    }
//    fclose(stdout);

    return 0;
}
