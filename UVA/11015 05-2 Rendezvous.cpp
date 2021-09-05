#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

const int MX = 1e9 ;
int n, m, cost[25][25];
string names[25] ;

void floyd_warshall(){
	for(int k = 1 ; k <= n ; k++){
		for(int i = 1 ; i <= n; i++){
			if(cost[i][k] == MX)	continue ;
			for(int j = 1 ; j <= n; j++){
				if(cost[i][j] > cost[i][k] + cost[k][j]){
					cost[i][j] = cost[i][k] + cost[k][j] ;
				}
			}
		}
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int u, v, c , tc = 0;
	while(cin >> n >> m){
		if( (n | m) == 0)	break ;

		for(int i = 0 ; i < 25 ; i++)
			for(int j = 0 ; j < 25 ; j++)
				cost[i][j] = (i == j ? 0 : MX) ;

		for(int i = 1 ; i <= n; i++){
			cin >> names[i] ;
		}

		for(int i = 0 ; i < m ; i++){
			cin >> u >> v >> c ;
			cost[u][v] = cost[v][u] = c ;
		}

		floyd_warshall() ;
		int minm = MX, id = -1 ;
		
		for(int i = 1 ; i <= n ; i++){
			int totalCost = 0 ;

			for(int j = 1 ; j <= n; j++){
				totalCost += cost[i][j] ;
			}

			if(totalCost < minm){
				minm = totalCost ;
				id = i ;
			}
		}

		cout<< "Case #"<< ++tc << " : " << names[id] << endl ;
	}

	return 0;
}