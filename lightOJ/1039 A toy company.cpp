#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int forbidden[27][27][27];
int vis[27][27][27];

int dx[] = {1, 25, 0, 0, 0, 0};
int dy[] = {0, 0, 1, 25, 0, 0};
int dz[] = {0, 0, 0, 0, 1, 25};

struct node{
    int a, b, c;
    
    node(int a=0, int b=0, int c=0){
        this -> a = a;
        this -> b = b;
        this -> c = c;
    }
    
    bool operator == (const node &n){
        return (a==n.a && b==n.b && c==n.c);
    }

    void visit(int d){
        vis[a][b][c] = d+1;
    }
    int visVal(){
        return vis[a][b][c];
    }
    void generate(queue<node>&q){
        for(int i=0; i<6; i++){
            if(vis[ (a+dx[i])%26 ][ (b+dy[i])%26 ][ (c+dz[i])%26 ])
                continue;
            if(forbidden[ (a+dx[i])%26 ][ (b+dy[i])%26 ][ (c+dz[i])%26 ])
                continue;
            vis[ (a+dx[i])%26 ][ (b+dy[i])%26 ][ (c+dz[i])%26 ] = vis[a][b][c] + 1;
            q.push(node( (a+dx[i])%26, (b+dy[i])%26, (c+dz[i])%26 ));
        }
    }
};

int bfs(node s, node t){
    if(forbidden[s.a][s.b][s.c] || forbidden[t.a][t.b][t.c])
        return -1;
    if(s==t)    return 0;

    memset(vis, 0, sizeof vis);
    queue<node> q;
    q.push(s);
    s.visit(0);

    while(!q.empty()){
        q.front().generate(q);
        q.pop();

        if(t.visVal() != 0)
            return (t.visVal()-1);
    }

    return -1;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin>> t;
    for(int tc=1; tc<=t ;tc++){
        memset(forbidden, 0, sizeof forbidden);
        string a, b, c;
        
        cin>> a;
        node from{a[0]-'a', a[1]-'a', a[2]-'a'};
        
        cin>> a;
        node to{a[0]-'a', a[1]-'a', a[2]-'a'};
        
        int n;
        cin>> n;
        
        while(n--){
            cin>> a>> b>> c;
            for(auto i: a){
                for(auto j: b){
                    for(auto k: c){
                        forbidden[i-'a'][j-'a'][k-'a'] = 1;
                    }
                }
            }
        }

        cout<< "Case "<< tc<< ": "<< bfs(from, to)<< endl;
    }

    return 0;
}
