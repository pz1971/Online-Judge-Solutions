#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

map<string, vector<string>> g;
map<string, int> vis;
int bfs(string s, string t){

    vis.clear();
    queue<string> q;
    q.push(s);
    vis[s] = 0;
    while(!q.empty()){
        string temp = q.front();
        q.pop();
        for(int i=0; i<g[temp].size(); i++){
            string str = g[temp][i];
            if(!vis.count(str)){
                vis[str] = vis[temp] + 1;
                if(str == t)
                    return vis[t];
                q.push(str);
            }
        }
    }

    return -1;
}

int main(){

    int t;
    cin>> t;
    cout<< "SHIPPING ROUTES OUTPUT\n";
    
    for(int tc=1; tc<=t; tc++){
        g.clear();

        cout<< "\nDATA SET  "<< tc<< "\n\n";
        
        int n, m, p, x, y;
        cin>> m>> n>> p;
        string a, b;
        for(int i=0; i<m; i++){
            cin>> a;
            g[a];
        }
        for(int i=0; i<n; i++){
            cin>> a>> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        for(int i=0; i<p; i++){
            cin>> x>> a>> b;
            y = bfs(a, b);
            if(y==-1)
                cout<< "NO SHIPMENT POSSIBLE\n";
            else
                cout<< "$"<< 100*x*y<< endl;
        }
    }

    cout<<  "\nEND OF OUTPUT\n";

    return 0;
}
