#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

string g[100005] ;
int n ;
map<pair<int, int> , int> vis ;

int dx[] = {0, 0, 1, -1} ;
int dy[] = {1, -1, 0, 0} ;

inline bool valid(int x, int y){
	return (x >= 0 && x < n && y >= 0 && y < n && vis[{x, y}] == 0) ;
}

int BFS(const pair<int, int> &start){
	vis.clear() ;
	queue<pair<int, int>> q ;
	q.push(start) ;
	vis[start] = 1 ;

	while(!q.empty()){
		pair<int, int> cur = q.front() ;
		q.pop() ;

		for(int i = 0 ; i < 4 ; i++){
			int x = cur.first + dx[i], y = cur.second + dy[i] ;
			if(!valid(x, y))
				continue ;

			if(g[x][y] == '3')
				return vis[cur] ;
			
			vis[{x, y}] = vis[cur] + 1 ;
			q.push({x, y}) ;
		}
	}

	return INT_MAX ;
}

int main(){

	while(cin >> n){
		vector<pair<int, int>> ones ;
		for(int i = 0 ; i < n ;i++){
			cin >> g[i] ;
			for(int j = 0 ; j < n ; j++){
				if(g[i][j] == '1')
					ones.push_back({i, j}) ;
			}
		}

		int ans = 0 ;
		for(auto i : ones){
			ans = max(ans, BFS(i)) ;
		}

		cout << ans << endl ;
	}

	return 0;
}