#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;
typedef pair<int, PII>  PIII;

int n, m, g[1000][1000] ;
int cost[1000][1000] ;

bool valid(int x , int y, int _cost){
	return (x >= 1 && x <= n && y >= 1 && y <= m && _cost < cost[x][y]) ;
}

int dx[] = {0, 0, 1, -1} ;
int dy[] = {1, -1, 0, 0} ;

int dijkstra(){
	priority_queue< PIII , vector<PIII> , greater<PIII> > pq ;
	pq.push({g[1][1], {1, 1}}) ;
	cost[1][1] = g[1][1] ;

	int x, y, c ;

	while(!pq.empty()){
		c = pq.top().first ;
		x = pq.top().second.first ;
		y = pq.top().second.second ;
		pq.pop() ;

		if(x == n && y == m)
			return c ;

		for(int i = 0 ; i < 4 ; i++){
			if(!valid(x + dx[i] , y + dy[i] , c + g[ x+dx[i] ][ y+dy[i] ]))
				continue ;
			
			pq.push({c + g[ x+dx[i] ][ y+dy[i] ] , {x + dx[i] , y + dy[i]}}) ;
			cost[ x+dx[i] ][ y+dy[i] ] = c + g[ x+dx[i] ][ y+dy[i] ] ;
		}
	}

	return INT_MAX ;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t ;
	cin >> t ;

	while(t--){
		cin >> n >> m ;
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= m ; j++){
				cin >> g[i][j] ;
				cost[i][j] = INT_MAX ;
			}
		}

		cout << dijkstra() << endl ;
	}

	return 0;
}