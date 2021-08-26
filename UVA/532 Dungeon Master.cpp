#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

struct triple{
    int x, y, z;
    triple(){
        x = -1;  y = -1; z = -1;
    }
    triple(int x, int y, int z){
        this-> x = x;
        this-> y = y;
        this-> z = z;
    }
};
triple Start, End;

int dx[] = {0, 0, 0, 0, 1, -1};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {1, -1, 0, 0, 0, 0};

int vis[55][55][55], dis[55][55][55], BIG;
int l, r, c;

bool valid(int x, int y, int z){
    return (x>=0 && x<l && y>=0 && y<r && z>=0 && z<c && vis[x][y][z]==0);
}

void visit(triple &t){
    vis[t.x][t.y][t.z] = 1;
}

void bfs(){
    queue<triple> q;
    q.push(Start);
    dis[Start.x][Start.y][Start.z] = 0;
    visit(Start);
    while(!q.empty()){
        triple temp = q.front();    q.pop();
        if(temp.x == End.x && temp.y == End.y && temp.z == End.z)   break;
        for(int i=0; i<6; i++){
            if(valid(temp.x+dx[i], temp.y+dy[i], temp.z+dz[i])){
                triple t(temp.x+dx[i], temp.y+dy[i], temp.z+dz[i]);
                q.push(t);  visit(t);
                dis[t.x][t.y][t.z] = dis[temp.x][temp.y][temp.z] + 1;
            }
        }
    }
}

int main(){

    memset(&BIG, 127, sizeof (int));
    char ch;
    while(scanf("%d %d %d", &l, &r, &c) != EOF){
        getchar();
        if(!l && !r && !c)  break;
        memset(vis, 0, sizeof vis);
        memset(dis, 127, sizeof dis);
        for(int i=0; i<l; i++){
            for(int j=0; j<r; j++){
                for(int k=0; k<c; k++){
                    ch = getchar();
                    if(ch=='#')
                        vis[i][j][k] = 1;
                    else if(ch=='S'){
                        Start.x = i;
                        Start.y = j;
                        Start.z = k;
                    }
                    else if(ch=='E'){
                        End.x = i;
                        End.y = j;
                        End.z = k;
                    }
                }
                getchar();
            }
            getchar();
        }
        bfs();
        if(dis[End.x][End.y][End.z] == BIG)
            printf("Trapped!\n");
        else
            printf("Escaped in %d minute(s).\n", dis[End.x][End.y][End.z]);
    }

    return 0;
}