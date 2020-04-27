#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int r, c ;
vector<string> g ;

const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1} ;
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1} ;

inline bool valid(int x, int y){
	return (x >= 0 && x < r && y >= 0 && y < c) ;
}

int _0_1_BFS(const pair<int, int> s, const pair<int, int> t){
	vector<vector<int> > vis (r, vector<int> (c, -1)) ;

	deque<pair<int, int> > dq ;
	dq.push_back(s) ;
	vis[s.first][s.second] = 0 ;

	while(!dq.empty()){
		int x = dq.front().first ;
		int y = dq.front().second ;
		dq.pop_front() ;

		if(make_pair(x, y) == t){
			return vis[x][y] ;
		}
		
		for(int i = 0 ; i < 8 ; i++){
			int nx = x + dx[i] ;
			int ny = y + dy[i] ;

			if(!valid(nx, ny))	continue ;

			if(g[x][y] == '0' + i){
				if(vis[nx][ny] == -1 || vis[nx][ny] > vis[x][y]){
					vis[nx][ny] = vis[x][y] ;
					dq.push_front({nx, ny}) ;
				}
			}
			else{
				if(vis[nx][ny] == -1){
					vis[nx][ny] = vis[x][y] + 1 ;
					dq.push_back({nx, ny}) ;
				}
			}
		}
	}

	return INT_MAX ;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> r >> c ;
	g = vector<string> (r) ;
	for(auto &i : g)
		cin >> i ;
	
	int n ;
	cin >> n ;

	while(n--){
		pair<int, int> start, finish ;
		cin >> start.first >> start.second ;
		cin >> finish.first >> finish.second ;
		
		start.first-- ; start.second-- ;
		finish.first-- ; finish.second-- ;

		cout << _0_1_BFS(start, finish) << endl ;
	}

	return 0;
}