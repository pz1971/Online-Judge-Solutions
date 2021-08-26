#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int t, r, c, jx, jy;
char g[205][205];
queue<PII> fires;
int fireTime[205][205];
int vis[205][205];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool fireCanGetHere(int x, int y){
	return (x >= 0 && x < r && y >= 0 && y < c && g[x][y] == '.' && fireTime[x][y] == 0);
}

bool inEdge(int x, int y){
	return (x == 0 || y == 0 || x == r-1 || y == c-1);
}

bool valid(int x, int y, int time){
	return (x >= 0 && x < r && y >= 0 && y < c && vis[x][y] == 0 && time < fireTime[x][y]);
}

void spreadFire(){
	int x, y;
	while(!fires.empty()){
		x = fires.front().first;
		y = fires.front().second;
		fires.pop();
		
		for(int i=0; i<4; i++){
			if(fireCanGetHere(x + dx[i] , y + dy[i])){
				fires.push(make_pair(x + dx[i] , y + dy[i]));
				fireTime[x + dx[i]][y + dy[i]] = fireTime[x][y] + 1;
			}
		}
	}
}

int bfs(){
	if(inEdge(jx, jy))
		return 1;
	
	queue<PII> q;
	q.push(make_pair(jx, jy));
	vis[jx][jy] = 1;

	int x, y;
	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for(int i=0; i<4; i++){
			if(valid(x + dx[i], y + dy[i], vis[x][y] + 1)){
				if(inEdge(x + dx[i], y + dy[i]))
					return vis[x][y] + 1;
				q.push(make_pair(x + dx[i] , y + dy[i]));
				vis[x + dx[i]][y + dy[i]] = vis[x][y] + 1;
			}
		}
	}

	return -1;
}

int main(){

	int ans;
	scanf("%d", &t);
	
	for(int tc = 1; tc <= t; tc++){
		memset(fireTime, 0, sizeof fireTime);
		memset(vis, 0, sizeof vis);

		scanf("%d %d", &r, &c);
		getchar();

		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				g[i][j] = getchar();
		
				if(g[i][j] == 'J'){
					jx = i;
					jy = j;
				}
		
				if(g[i][j] == 'F'){
					fires.push(make_pair(i, j));
					fireTime[i][j] = 1;
				}
			}
			getchar();
		}

		spreadFire();

		ans = bfs();
		if(ans >= 0)
			printf("Case %d: %d\n", tc, ans);
		else 
			printf("Case %d: IMPOSSIBLE\n", tc);
	}

	return 0;
}