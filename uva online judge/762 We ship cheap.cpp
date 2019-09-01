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

map<string, vector<string>> parent;

void bfs(string s, map<string, vector<string>> g ){
    queue<string> q;
    q.push(s);
    parent[s].pb(s);
    while(!q.empty()){
        string t = q.front();
        q.pop();
        for(auto i: g[t]){
            if(!parent.count(i)){
                parent[i].pb(t);
                q.push(i);
            }
        }
    }
}

int main(){

    fastIO;
    int n;
    bool first = true;
    while(cin>> n){
        if(first)   first = false;
        else        cout<< endl;
        parent.clear();
        map<string, vector<string>> g;
        string a, b;
        while(n--){
            cin>> a>> b;
            g[a].pb(b);
            g[b].pb(a);
        }
        cin>> a>> b;
        bfs(b, g);

        vector<string> route;
        route.pb(a);
        while(1){
            if(!parent.count(a))    break;
            if(a == parent[a][0])   break;
            a = parent[a][0];
            route.pb(a);
        }
        if(route.size()<2)  cout<< "No route\n";
        else{
            for(int i=1; i<route.size(); i++){
                cout<< route[i-1] << " "<< route[i]<< endl;
            }
        }
        cin.ignore();
        cin.ignore();
    }

    return 0;
}
