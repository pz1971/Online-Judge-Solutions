#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;
 
int w, h, vis[105][105];
char g[105][105];
PII s, t;
 
bool valid(int x, int y, int wt){
	return (x >= 0 && x < h && y >= 0 && y < w && g[x][y] != '*' && vis[x][y] >= wt);
}
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
 
int BFS(){
	queue<PII> q;
	q.push(s);
	vis[s.first][s.second] = 1;
 
	while(!q.empty()){
		PII cur = q.front();
		q.pop();
 
		for(int i=0; i<4; i++){
			int x = cur.first + dx[i], y = cur.second + dy[i];
 
			while(valid(x, y, vis[cur.first][cur.second] + 1)){
				q.push(make_pair(x, y));
				vis[x][y] = vis[cur.first][cur.second] + 1;
				x += dx[i];
				y += dy[i];
 
				if(vis[t.first][t.second] != INT_MAX)
					return vis[t.first][t.second] - 2;
			}
		}
	}
 
	return -1;
}
 
int main(){
 
	for(int i=0; i<105; i++)
		for(int j=0; j<105; j++)
			vis[i][j] = INT_MAX;
	
	scanf("%d %d", &w, &h);
	getchar();
 
	for(int i=0; i < h; i++){
		for(int j=0; j<w; j++){
			g[i][j] = getchar();
 
			if(g[i][j] == 'C'){
				swap(s, t);
				t.first = i;
				t.second = j;
			}
		}
		getchar();
	}
 
	printf("%d\n", BFS());
 
	return 0;
}
