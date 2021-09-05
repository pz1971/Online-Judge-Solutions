#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define sf(a) scanf("%d", &a)
#define sff(a, b) scanf("%d %d", &a, &b)
typedef long long ll;
using namespace std;

vi g[105];
int level[105];
void bfs(int s){
    queue<int> q;
    q.push(s);
    level[s] = 0;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(auto i: g[t]){
            if(level[i]!=-1)    continue;
            q.push(i);
            level[i] = level[t]+1;
        }
    }
}

int main(){

    int tc = 0;
    int a, b, mxNode=0;
    set<int> nodes;
    while(sff(a, b)!= EOF && (a || b)){
        mxNode = max(mxNode, max(a, b));
        g[a].pb(b);
        nodes.insert(a);nodes.insert(b);
        while(sff(a, b)!=EOF && (a || b)){
            g[a].pb(b);
            nodes.insert(a);nodes.insert(b);
            mxNode = max(mxNode, max(a, b));
        }

        double ans = 0.0;
        for(int i=0; i<=mxNode; i++){
            bfs(i);
            for(int i=0; i<=mxNode; i++){
                if(level[i]!=-1)
                    ans += level[i];
            }
            memset(level, -1, sizeof level);
        }
        ans = ans / ((int)nodes.size()*((int)nodes.size()-1));

        printf("Case %d: average length between pages = %.3lf clicks\n", ++tc, ans);

        for(int i=0; i<=mxNode; i++)    g[i].clear();
        mxNode = 0;
        nodes.clear();
    }

    return 0;
}
