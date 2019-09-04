#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

char g[13][13];
int posX[27], posY[27];
int t, n, k;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int vis[12][12];

bool valid(int x, int y){
	return (x >= 0 && x < n && y >= 0 && y < n && vis[x][y] == 0 && g[x][y] == '.');
}

int bfs(int s){
	memset(vis, 0, sizeof vis);
	queue<PII> q;
	q.push(make_pair(posX[s], posY[s]));
	vis[posX[s]][posY[s]] = 1;
	int x, y;

	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++){
			if(x + dx[i] == posX[s+1] && y + dy[i] == posY[s+1]){
				return vis[x][y];
			}
			if(valid(x + dx[i], y + dy[i])){
				q.push(make_pair(x + dx[i] , y + dy[i]));
				vis[x + dx[i]][y + dy[i]] = vis[x][y] + 1;
			}
		}
	}

	return -1;
}

int main(){

	scanf("%d", &t);
	for(int tc = 1; tc<= t; tc++){
		scanf("%d", &n);
		getchar();
		k = 0;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				g[i][j] = getchar();
				if(g[i][j] != '.' && g[i][j] != '#'){
					k++;
					posX[g[i][j] - 'A'] = i;
					posY[g[i][j] - 'A'] = j;
				}
			}
			getchar();
		}
		
		if(k == 1){
			printf("Case %d: 0\n", tc);
			continue;
		}

		int ans = 0, x;
		for(int i=0; i + 1 < k; i++){
			x = bfs(i);
			if(x < 0){
				ans = -1;
				break;
			}
			ans += x;
			g[posX[i]][posY[i]] = '.';
		}
		if(ans >= 0)
			printf("Case %d: %d\n", tc, ans);
		else 
			printf("Case %d: Impossible\n", tc);
	}

	return 0;
}