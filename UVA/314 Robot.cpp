#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int n, m ;
int ob[51][51], vis[51][51][4] ;

int dx[] = {-1, 0, 1, 0} ;
int dy[] = {0, 1, 0, -1} ;

class node{
public:
	int x, y, dir, w ;
	node(){
	}
	node(int _x, int _y, int _dir, int _w)
	: x(_x), y(_y), dir(_dir), w(_w) {
	}
} B, E ;

bool valid(int x, int y){
	return (
		x > 0 && x < m && y > 0 && y < n &&
		!(ob[x-1][y-1] || ob[x-1][y] || ob[x][y] || ob[x][y-1])
	) ;
}

int BFS(){
	if(!valid(B.x, B.y))
		return -1 ;
	
	queue<node> q ;
	B.w = 0 ;
	vis[B.x][B.y][B.dir] = 1 ;
	q.push(B) ;

	while(!q.empty()){
		node cur = q.front() ;
		q.pop() ;
		
		if(cur.x == E.x && cur.y == E.y)
			return cur.w ;

		// Turn
		if(!vis[cur.x][cur.y][(cur.dir + 1) % 4]){
			vis[cur.x][cur.y][(cur.dir + 1) % 4] = 1 ;
			q.push({cur.x, cur.y, (cur.dir + 1) % 4, cur.w + 1}) ;
		}
		if(!vis[cur.x][cur.y][(cur.dir + 3) % 4]){
			vis[cur.x][cur.y][(cur.dir + 3) % 4] = 1 ;
			q.push({cur.x, cur.y, (cur.dir + 3) % 4, cur.w + 1}) ;
		}
		// GO
		for(int i = 1 ; i <= 3 ; i++){
			if(valid(cur.x+dx[cur.dir]*i, cur.y+dy[cur.dir]*i)){
				if(!vis[ cur.x+dx[cur.dir]*i ][ cur.y+dy[cur.dir]*i ][ cur.dir ]){
					vis[ cur.x+dx[cur.dir]*i ][ cur.y+dy[cur.dir]*i ][ cur.dir ] = 1 ;
					q.push({cur.x+dx[cur.dir]*i, cur.y+dy[cur.dir]*i, cur.dir, cur.w+1}) ;
				}
			}
			else break ;
		}
	}

	return -1 ;
}

int main(){

	string str ;
	while(cin >> m >> n){
		if(!(m | n))	break ;
		memset(vis, 0, sizeof vis);

		for(int i = 0 ; i < m ; i++)
			for(int j = 0 ; j < n ; j++)
				cin >> ob[i][j] ;
		
		cin >> B.x >> B.y >> E.x >> E.y >> str ;
		
		if(str == "north")
			B.dir = 0 ;
		else if(str == "east")
			B.dir = 1 ;
		else if(str == "south")
			B.dir = 2 ;
		else if(str == "west")
			B.dir = 3 ;
		
		cout << BFS() << endl ;
	}

	return 0;
}