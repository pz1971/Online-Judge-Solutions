#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int t, n, ans;
char g[11][11];
int vis[11][11][11][11][11][11];
vector<PII> robots;

void clearAll(){
	robots.clear();
	memset(vis, 0, sizeof vis);
}

void getInput(){
	scanf("%d", &n);
	getchar();

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			g[i][j] = getchar();
			
			if(g[i][j] >= 'A' && g[i][j] <= 'C')
				robots.push_back(make_pair(i, j));
		}
		getchar();
	}
}

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool valid(int x, int y){
	return ( x >= 0 && x < n && y >= 0 && y < n && g[x][y] != '#' );
}

bool done( const vector<PII> &vec ){
	for(int i=0; i<3; i++){
		if(g[vec[i].first][vec[i].second] != 'X')
			return false;
	}
	return true;
}

void visit(const vector<PII> &vec, int _val){
	vis[vec[0].first][vec[0].second][vec[1].first][vec[1].second][vec[2].first][vec[2].second] = _val ;
}

int visVal(const vector<PII> &vec){
	return (vis[vec[0].first][vec[0].second][vec[1].first][vec[1].second][vec[2].first][vec[2].second]) ;
}

int chk[] = {0, 0, 0};
void move(vector<PII> &vec, int idx, int DX, int DY){
	chk[idx] = 1;
	
	if(!valid(vec[idx].first + DX, vec[idx].second + DY)){
		return;
	}
	
	const PII p = make_pair(vec[idx].first + DX, vec[idx].second + DY);
	
	if(p == vec[(idx + 1) % 3]){
		move(vec, (idx + 1) % 3, DX, DY);
		if(p != vec[(idx + 1) % 3]){
			vec[idx] = p;
		}
		return;
	}

	if(p == vec[(idx + 2) % 3]){
		move(vec, (idx + 2) % 3, DX, DY);
		if(p != vec[(idx + 2) % 3]){
			vec[idx] = p;
		}
		return;
	}

	vec[idx] = p;
}

int BFS(){
	queue< vector<PII> > q;
	q.push(robots);
	
	visit(robots, 1);

	while(!q.empty()){
		vector<PII> cur = q.front();

		q.pop();

		for(int i=0; i<4; i++){
			vector<PII> temp = cur;

			memset(chk, 0, sizeof chk);

			for(int j = 0; j<3; j++){
				if(chk[j])	
					continue;
				move(temp, j, dx[i], dy[i]);
			}
			
			if(visVal(temp))
				continue;

			if(done(temp))
				return visVal(cur);
			
			visit(temp, visVal(cur) + 1);
			q.push(temp);
		}
	}

	return -1;
}

int main(){

	scanf("%d", &t);

	for(int tc = 1; tc <=t; tc++){
		clearAll();
		getInput();

		ans = BFS();
		
		if(ans == -1)
			printf("Case %d: trapped\n", tc);
		else 
			printf("Case %d: %d\n", tc, ans);
	}

	return 0;
}