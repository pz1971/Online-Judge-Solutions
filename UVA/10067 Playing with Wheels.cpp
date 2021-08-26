#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int forbidden[10][10][10][10];
int vis[10][10][10][10];

struct node{
    int d[4];
    node(int d1=0, int d2=0, int d3=0, int d4=0){
        this -> d[0] = d1;
        this -> d[1] = d2;
        this -> d[2] = d3;
        this -> d[3] = d4;
    }
    node(int ar[]){
        for(int i=0; i<4; i++)
            d[i] = ar[i];
    }
    bool operator==(const node &n1){
        return (d[0]==n1.d[0] && d[1]==n1.d[1] &&
                d[2]==n1.d[2] && d[3]==n1.d[3]); 
    }

    int val(){
        return ( vis[d[0]][d[1]][d[2]][d[3]] );
    }
    void visit(int w){
        vis[d[0]][d[1]][d[2]][d[3]] = w + 1;
    }
    bool ifNotForbidden(){
        return (forbidden[d[0]][d[1]][d[2]][d[3]]==0);
    }
};

int bfs(node s, node t){
    memset(vis, 0, sizeof vis);
    node a, b;
    
    queue<node> q;
    q.push(s);
    s.visit(0);
    
    while(!q.empty()){
        a = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            b = a;
            b.d[i] = (b.d[i] + 1) % 10;
            if(b.val() == 0 && b.ifNotForbidden()){
                b.visit(a.val());
                if(b == t)
                    break;
                q.push(b);
            }
        }
        for(int i=0; i<4; i++){
            b = a;
            b.d[i] = (b.d[i] + 9) % 10;
            if(b.val() == 0 && b.ifNotForbidden()){
                b.visit(a.val());
                if(b == t)
                    break;
                q.push(b);
            }
        }
    }

    return t.val() - 1;
}

int main(){

    int t;
    scanf("%d", &t);
    while(t--){
        memset(forbidden, 0, sizeof forbidden);
        int n;
        int d1, d2, d3, d4;
        scanf("%d %d %d %d", &d1, &d2, &d3, &d4);
        node s {d1, d2, d3, d4};
        scanf("%d %d %d %d", &d1, &d2, &d3, &d4);
        node t {d1, d2, d3, d4};
        scanf("%d", &n);
        while(n--){
            scanf("%d %d %d %d", &d1, &d2, &d3, &d4);
            forbidden[d1][d2][d3][d4] = 1;
        }
        printf("%d\n", bfs(s, t));
    }

    return 0;
}