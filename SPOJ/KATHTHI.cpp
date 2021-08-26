#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 1005 ;

int r, c;
string mapp[mx] ;
int vis[mx][mx] ;

int dx[] = {0, 0, 1, -1} ;
int dy[] = {1, -1, 0, 0} ;

inline bool valid(int x, int y){
	return (x >= 0 && x < r && y >= 0 && y < c) ;
}

int _0_1_BFS(){
	for(int i = 0 ; i < r ; i++)
		for(int j = 0 ; j < c ; j++)
			vis[i][j] = INT_MAX ;
	
	deque<pair<int, int> > dq ;
	dq.push_back({0, 0}) ;
	vis[0][0] = 0 ;

	while(!dq.empty()){
		pair<int, int> cur = dq.front() ;
		dq.pop_front() ;

		if(cur.first == r-1 && cur.second == c-1)
			break ;

		for(int i = 0 ; i < 4 ; i++){
			int x = cur.first + dx[i] ;
			int y = cur.second + dy[i] ;

			if(!valid(x, y) || vis[x][y] <= vis[cur.first][cur.second])
				continue ;

			if(mapp[cur.first][cur.second] == mapp[x][y]){
				dq.push_front(make_pair(x, y)) ;
				vis[x][y] = vis[cur.first][cur.second] ;
			}
			else if(vis[x][y] > vis[cur.first][cur.second] + 1){
				dq.push_back(make_pair(x, y)) ;
				vis[x][y] = vis[cur.first][cur.second] + 1 ;
			}
		}
	}

	return vis[r-1][c-1] ;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int test_case ;
	cin >> test_case ;
	
	while(test_case--){
		cin >> r >> c ;
		for(int i = 0 ; i < r ; i++)
			cin >> mapp[i] ;
		
		cout << _0_1_BFS() << endl ;
	}	

	return 0;
}