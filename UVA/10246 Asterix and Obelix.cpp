#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

const int MX = 85, MX_VAL = 1e8 ;
int cost[MX], dis[MX][MX], worstCost[MX][MX] ;

void floyd_warshall(int n){
	for(int k = 1; k<=n; k++){
		for(int i=1; i <= n ; i++){
			if(dis[i][k] >= MX_VAL)		continue ;

			for(int j =1 ; j<=n ; j++){
				if(dis[k][j] >= MX_VAL)		continue ;
				
				if( dis[i][j] + worstCost[i][j] >
						dis[i][k] + dis[k][j] + max(worstCost[i][k] , worstCost[k][j]) ){
					dis[i][j] = dis[j][i] = dis[i][k] + dis[k][j] ;
					worstCost[i][j] = worstCost[j][i] = max(worstCost[i][k] , worstCost[k][j]) ;
				}
			}
		}
	}
}

int main(){

	int c, r, q, tc = 0;
	while(cin>> c>> r>> q){
		if((c | r | q) == 0)	break ;
		if(tc)		cout<< endl ;

		for(int i=1 ; i <= c ; i++){
			cin>> cost[i] ;

			worstCost[i][i] = cost[i] ;
			dis[i][i] = 0;

			for(int j = i + 1 ; j <= c ; j++){
				dis[i][j] = dis[j][i] = MX_VAL ;
				worstCost[i][j] = dis[j][i] = MX_VAL ;
			}
		}
		printf("Case #%d\n", ++tc);

		int c1, c2, d ;
		while(r--){
			cin>> c1>> c2>> d;
			dis[c1][c2] = dis[c2][c1] = d ;
			worstCost[c1][c2] = worstCost[c2][c1] = max(cost[c1], cost[c2]) ;
		}

		floyd_warshall(c) ;
		floyd_warshall(c) ;

		int ans ;
		while(q--){
			cin>> c1>> c2 ;
			ans = dis[c1][c2] + worstCost[c1][c2] ;
			if(ans >= MX_VAL)	cout<< "-1"<< endl;
			else 				cout<< ans << endl;
		}
	}

	return 0;
}