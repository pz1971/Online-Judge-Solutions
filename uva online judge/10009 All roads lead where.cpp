#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

VI g[30];
int parent[30];

void printParent(int child){
    if(parent[child] > -1)
        printParent(parent[child]);
    cout<< (char)(child + 'A');
}

void bfs(int s, int t){
    
    memset(parent, -1, sizeof parent);

    queue<int> q;
    q.push(s);
    parent[s] = -2;
    
    while(!q.empty()){
        int temp = q.front();
        q.pop();

        for(size_t i = 0; i < g[temp].size(); i++){
            int x = g[temp][i];
            if(parent[x] == -1){
                parent[x] = temp;
                if(x == t){
                    printParent(x);
                    break;
                }
                q.push(x);
            }
        }
    }
}

int main(){

    int t, m, n;
    cin>> t;
    
    while (t--)
    {
        getchar();
        cin>> m>> n;
        
        getchar();
        string a, b;

        for(int i=0; i<30; i++)
            g[i].clear();
        
        for(int i=0; i<m; i++){
            cin>> a>> b;
            
            g[(int)(a[0] - 'A')].push_back((int)(b[0] - 'A'));
            g[(int)(b[0] - 'A')].push_back((int)(a[0] - 'A'));
        }
        
        for(int i=0; i<n; i++){
            cin>> a>> b;
            bfs((int)(a[0]-'A'), (int)(b[0]-'A'));
            cout<< endl;
        }
        
        if(t)   cout<< endl;
    }

    return 0;
}
