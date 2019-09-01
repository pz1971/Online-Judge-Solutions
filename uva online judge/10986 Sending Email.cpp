#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int big;
map<PII, int> w;
int d[20005];

int dijkstra(int n, int s, int t, VI g[]){
    memset(d, 127, sizeof d);

    d[s] = 0;
    priority_queue<int, VI, greater<int>> q;
    q.push(s);
    while(!q.empty()){
        int temp = q.top();
        q.pop();
        for(auto i: g[temp]){
            if(d[i] > d[temp] + w[make_pair(i, temp)]){
                q.push(i);
                d[i] = d[temp] + w[make_pair(i, temp)];
            }
        }
    }

    return d[t];
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(&big, 127, sizeof (int));
    int test;
    cin>> test;
    for(int tc=1; tc<=test; tc++){
        w.clear();
        int n, m, s, t, a, b, weight, ans;
        cin>> n>> m>> s>> t;
        VI g[n+5];
        while(m--){
            cin>> a>> b>> weight;
            g[a].push_back(b);
            g[b].push_back(a);
            w[make_pair(a, b)] = weight;
            w[make_pair(b, a)] = weight;
        }
        ans = dijkstra(n, s, t, g);
        cout<< "Case #"<< tc<< ": ";
        ans == big ? cout<< "unreachable\n" : cout<< ans<< endl;
    }

    return 0;
}
