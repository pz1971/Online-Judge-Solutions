#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int visited[30];
VI g[30];

void dfs(int s){
    visited[s] = 1;
    for(auto i: g[s])
        if(!visited[i])
            dfs(i);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin>> t;
    cin.ignore();
    string s;
    getline(cin, s);
    while(t--){
        memset(visited, 0, sizeof visited);
        for(int i=0; i<30; i++)
            g[i].clear();

        getline(cin, s);
        int mxNode = s[0] - 'A' + 1;

        while(1){
            getline(cin, s);
            if(s.empty()) break;
            g[s[0] - 'A'].push_back(s[1] - 'A');
            g[s[1] - 'A'].push_back(s[0] - 'A');
        }

        int cnt = 0;
        for(int i=0; i<mxNode; i++){
            if(visited[i])      continue;
            dfs(i);
            cnt++;
        }
        cout<< cnt<< endl;
        if(t) cout<< endl;
    }

    return 0;
}
