#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

class triple
{
public:
    int w, t, d;
    triple();
    triple(int w, int t, int d){
        this-> w = w;
        this-> t = t;
        this-> d = d;
    }
};

triple make_triple(int x, int y, int z){
    triple temp(x, y, z);
    return temp;
}

class cmp{
public:
    bool operator()(triple t1, triple t2){
        return (t1.w > t2.w);
    }
};


int dijkstra(int n, int D, vector<triple>g[]){
    priority_queue<triple, vector<triple>, cmp> q;
    q.push(make_triple(0, 0, 0));
    int usedD, currentNode, weightSoFar, tempNode, tempWeight, tempD;
    while(!q.empty()){
        usedD = q.top().d; currentNode = q.top().t;
        weightSoFar = q.top().w; q.pop();

        if(currentNode == n)    return weightSoFar;

        for(int i=0; i<g[currentNode].size(); i++){
            tempNode = g[currentNode][i].t;
            tempWeight = g[currentNode][i].w;
            tempD = g[currentNode][i].d;

            if(usedD + tempD > D)   continue;
            q.push(make_triple(weightSoFar+tempWeight, tempNode, usedD+tempD));
        }
    }
    return -1;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin>> t;
    for(int tc=1; tc<=t; tc++){
        int n, m, k, d;
        cin>> n>> m>> k>> d;
        vector<triple> g[n+5];
        int u, v, w;
        for(int i=0; i<m; i++){
            cin>> u>> v>> w;
            g[u].push_back(make_triple(w, v, 0));
        }
        for(int i=0; i<k; i++){
            cin>> u>> v>> w;
            g[u].push_back(make_triple(w, v, 1));
        }
        int ans = dijkstra(n-1, d, g);
        cout<< "Case "<< tc<< ": ";
        if(ans == -1)   cout<< "Impossible\n" ;
        else            cout<< ans<< endl;
    }

    return 0;
}
