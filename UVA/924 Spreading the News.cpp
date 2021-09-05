#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

VI g[2505];
int mark[2505];
int a, b;

void bfs(int s){
    memset(mark, 0, sizeof mark);
    VI vec1, vec2;
    vec1.push_back(s);
    mark[s] = 1;
    int d = 0;
    a = b = 0;

    while(!vec1.empty()){
        for(auto i: vec1){
            for(auto j: g[i]){
                if(!mark[j]){
                    vec2.push_back(j);
                    mark[j] = 1;
                }
            }
        }
        vec1 = vec2;
        vec2.clear();
        d++;
        if(vec1.size() > a){
            a = vec1.size();
            b = d;
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int e;
    cin>> e;
    for(int i=0; i<e; i++){
        int n, x;
        cin>> n;
        for(int j=0; j<n; j++){
            cin>> x;
            g[i].push_back(x);
        }
    }

    int t, s;
    cin>> t;
    while(t--){
        cin>> s;
        bfs(s);
        cout<< a;
        if(a)   cout<< " "<< b;
        cout<< endl;
    }

    return 0;
}
