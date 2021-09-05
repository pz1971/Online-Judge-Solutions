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

map<pair<short, short>, short> wt;
vector<short> g[30005];
int maxm = 0;
short mark[30005];

int dfs(int s, short w){
    mark[s] = 1;
    int mx=0, smx=0, x=0;
    for(auto i: g[s]){
        if(mark[i]) continue;
        x = dfs(i, wt[mp(s, i)]);
        if(x>=mx){
            smx = mx;
            mx = x;
        }
        else if(x>smx)
            smx = x;
    }
    maxm = max(maxm, mx+smx);
    mark[s] = 0;
    return mx+w;
}

int main(){

    fastIO;
//    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    short t;
    cin>> t;
    for(short tc=1; tc<=t; tc++){
        wt.clear();
        short n, a, b, w;
        maxm = 0;
        cin>> n;
        for(int i=1; i<n; i++){
            cin>> a>> b>> w;
            g[a].pb(b);
            g[b].pb(a);
            wt[mp(a, b)] = w;
            wt[mp(b, a)] = w;
        }
        dfs(0, 0);
        cout<< "Case "<< tc<< ": "<< maxm<< endl;
        for(short i=0; i<n; i++)  g[i].clear();
    }

    return 0;
}
