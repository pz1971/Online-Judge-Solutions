#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int n, m, parent[305], x;
stringstream ss;

void printParent(int child){
    if(parent[child] == -1)
        cout<< child;
    else{
        printParent(parent[child]);
        cout<< " "<< child;
    }
}

void bfs(int s, int t, VI g[]){
    if(s == t){
        cout<< s<< endl;
        return;
    }
    memset(parent, 0, sizeof parent);
    parent[s] = -1;
    queue<int> q;
    q.push(s);

    while(!q.empty()){
        int temp = q.front();   q.pop();
        for(int i=0; i<g[temp].size(); i++){
            x = g[temp][i];
            if(parent[x] != 0)  continue;
            parent[x] = temp;
            q.push(x);
            if(x == t){
                printParent(x);
                cout<< endl;
                return;
            }
        }
    }
    cout<< "connection impossible\n";
}

int main(){

    while(cin>> n){
        getchar();
        VI g[n+5];
        int u, v;
        char ch;
        string str;
        while(getline(cin, str)){
            ss.clear();
            ss<< str;
            ss >> u;
            while(ss>> ch>> v){
                g[u].push_back(v);
            }
            n--;
            if(!n) break;
        }
        for(int i=1; i<=n; i++)
            sort(g[i].begin(), g[i].end());
        cin>> m;
        cout<< "-----\n";
        while(m--){
            cin>> u>> v;
            bfs(u, v, g);
        }
    }

    return 0;
}