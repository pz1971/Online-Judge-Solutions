#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int n, m;
char g[1005][1005];
int vis[1005][1005];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool valid(int x, int y){
	return (x>=0 && x<m && y>=0 && y<n && g[x][y]!='#' && vis[x][y] < 0);
}

void bfs(int X, int Y){
	if(vis[X][Y] >= 0)
		return;
	int cnt = 0;
	if(g[X][Y] == 'C') cnt++;
	vector<PII> v;
	vis[X][Y] = 1;
	v.push_back(make_pair(X, Y));

	for(int i=0; i<v.size(); i++){
		int x = v[i].first;
		int y = v[i].second;

		for(int j=0; j<4; j++){
			if(!valid(x+dx[j] , y+dy[j]))
				continue;
			v.push_back(make_pair(x+dx[j], y+dy[j]));
			vis[x+dx[j]][y+dy[j]] = 1;
			if(g[x+dx[j]][y+dy[j]] == 'C')
				cnt++;
		}
	}
	for(PII p: v){
		vis[p.first][p.second] = cnt;
	}
}

int main(){

	int t;
	scanf("%d", &t);
	for(int tc=1; tc<=t; tc++){
		memset(vis, -1, sizeof vis);
		int q;
		scanf("%d %d %d", &m, &n, &q);
		getchar();
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				g[i][j] = getchar();
			}
			getchar();
		}
		int x, y;
		printf("Case %d:\n", tc);
		while(q--){
			scanf("%d %d", &x, &y);
			bfs(x-1, y-1);
			printf("%d\n", vis[x-1][y-1]);
		}
	}

	return 0;
}