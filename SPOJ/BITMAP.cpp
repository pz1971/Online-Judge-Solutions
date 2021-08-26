#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 200 ;
const int dx[] = {0, 0, 1, -1} ;
const int dy[] = {1, -1, 0, 0} ;

int n, m ;
string g[mx] ;
vector<pair<int, int> > whites ;
int vis[mx][mx] ;

inline bool valid(int x, int y){
	return (x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == -1) ;
}

void BFS(){
	memset(vis, -1, sizeof vis) ;

	queue<pair<int, int> > q ;
	for(auto i : whites){
		vis[i.first][i.second] = 0 ;
		q.push(i) ;
	}

	while(!q.empty()){
		int x = q.front().first ;
		int y = q.front().second ;
		q.pop() ;

		for(int i = 0 ; i < 4 ; i++){
			int tx = x + dx[i] ;
			int ty = y + dy[i] ;

			if(valid(tx, ty)){
				vis[tx][ty] = vis[x][y] + 1 ;
				q.push(make_pair(tx, ty)) ;
			}
		}
	}
}

int main(){

	int test_case ;
	cin >> test_case ;
	
	while(test_case--){
		cin >> n >> m ;

		whites.clear() ;
		for(int i = 0 ; i < n; i++){
			cin >> g[i] ;
			for(int j = 0 ; j < m ; j++){
				if(g[i][j] == '1')
					whites.push_back(make_pair(i, j)) ;
			}
		}

		BFS() ;

		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++)
				cout << vis[i][j] << " \n"[j == m - 1] ;
		}
	}

	return 0;
}