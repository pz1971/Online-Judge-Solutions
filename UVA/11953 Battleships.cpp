#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int t, n, cnt;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool valid(int x, int y){
	return (x >= 0 && x < n && y >= 0 && y < n);
}

char g[105][105];

void dfs(int x, int y){
	if(g[x][y] == '.')
		return ;
	
	g[x][y] = '.' ;

	for(int i=0; i<4; i++){
		if(valid(x + dx[i] , y + dy[i]))
			dfs(x + dx[i], y + dy[i]) ;
	}
}

int main(){

	scanf("%d", &t);
	
	for(int tc = 1; tc <= t; tc++){
		scanf("%d", &n);
		getchar();

		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++)
				g[i][j] = getchar();
			getchar();
		}

		cnt = 0;

		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(g[i][j] == 'x'){
					cnt++;
					dfs(i, j);
				}
			}
		}

		printf("Case %d: %d\n", tc, cnt);
	}

	return 0;
}