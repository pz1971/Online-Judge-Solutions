#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int R, C ;
int vis[1001][1001], bomb[1001][1001];
PII source, dest;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool valid(int X, int Y){
	return (X >= 0 && X < R && Y >= 0 && Y < C && vis[X][Y] == 0 && bomb[X][Y] == 0) ;
}

int bfs(){
	if(source == dest)
		return 0;
	
	queue<PII> q;
	q.push(source);
	vis[source.first][source.second] = 1;

	while(!q.empty()){
		PII cur = q.front();
		q.pop();

		for(int i=0; i<4; i++){
			if(valid(cur.first + dx[i] , cur.second + dy[i])){
				if(cur.first + dx[i] == dest.first && cur.second + dy[i] == dest.second)
					return vis[cur.first][cur.second] ;

				vis[cur.first + dx[i]][cur.second + dy[i]] = vis[cur.first][cur.second] + 1;
				q.push(make_pair(cur.first + dx[i] , cur.second + dy[i])) ;
			}
		}
	}

	return -1;
}

int main(){

	while(scanf("%d %d", &R, &C) != EOF && (R | C)){
		memset(vis, 0, sizeof vis);
		memset(bomb, 0, sizeof bomb);

		int n , m , u, v;
		scanf("%d", &n);
		
		while(n--){
			scanf("%d %d", &u, &m);
			while(m--){
				scanf("%d", &v);
				bomb[u][v] = 1;
			}
		}

		scanf("%d %d", &source.first, &source.second);
		scanf("%d %d", &dest.first, &dest.second);

		printf("%d\n", bfs());
	}

	return 0;
}