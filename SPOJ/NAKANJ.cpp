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

#define valid(x, y) ( x>0 && y>0 && x<9 && y<9 )
 
map<pii, int> level;
map<pii, vector<pii>> g;
 
void bfs(pii s, pii d){
    level.clear();
    queue<pii> q;
    q.push(s);
    level[s] = 0;
    while(!q.empty()){
        pii t = q.front();
        q.pop();
        for(auto i: g[t]){
            if(level.count(i))  continue;
            q.push(i);
            level[i] = level[t]+1;
            if(i==d)            break;
        }
    }
}
 
int main(){
 
    fastIO;
 
    for(int i=1; i<9; i++){
        for(int j=1; j<9; j++){
 
            if(valid(i+2, j+1))     g[mp(i, j)].pb(mp(i+2, j+1));
            if(valid(i+2, j-1))     g[mp(i, j)].pb(mp(i+2, j-1));
 
            if(valid(i-2, j+1))     g[mp(i, j)].pb(mp(i-2, j+1));
            if(valid(i-2, j-1))     g[mp(i, j)].pb(mp(i-2, j-1));
 
            if(valid(i+1, j+2))     g[mp(i, j)].pb(mp(i+1, j+2));
            if(valid(i-1, j+2))     g[mp(i, j)].pb(mp(i-1, j+2));
 
            if(valid(i+1, j-2))     g[mp(i, j)].pb(mp(i+1, j-2));
            if(valid(i-1, j-2))     g[mp(i, j)].pb(mp(i-1, j-2));
 
        }
    }
 
    int t;
    cin>> t;
    cin.ignore();
    while(t--){
        string a;
        cin>> a;
        pii s((a.at(0)-'a'+1) , (a.at(1)-'0'));
        cin>> a;
        pii d((a.at(0)-'a'+1) , (a.at(1)-'0'));
        bfs(s, d);
        cout<< level[d]<< endl;
    }
 
    return 0;
}
 