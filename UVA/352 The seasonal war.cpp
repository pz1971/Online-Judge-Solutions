#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int n;
char g[26][26];
int vis[26][26];

const int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dy[] = {1, -1, 0, 1, -1, 0, 1, -1};

bool valid(int x, int y){
	return (x >= 0 && x < n && y >= 0 && y < n && vis[x][y] == 0 && g[x][y] == '1') ;
}

void dfs(int x, int y){
	if(!g[x][y])
		return ;

	g[x][y] = '0' ;
	vis[x][y] = 1;

	for(int i=0; i<8; i++){
		if(valid(x + dx[i] , y + dy[i])){
			dfs(x + dx[i] , y + dy[i]) ;
		}
	}
}

int main(){

	int cnt, pic = 0;

	while(scanf("%d", &n) != EOF){
		getchar();
		memset(vis, 0, sizeof vis);

		for(int i=0; i < n ; i++){
			for(int j=0; j< n; j++)
				g[i][j] = getchar();
			getchar();
		}
		
		cnt = 0;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(g[i][j] == '1'){
					dfs(i, j);
					cnt++;
				}
			}
		}

		printf("Image number %d contains %d war eagles.\n", ++pic, cnt);
	}

	return 0;
}