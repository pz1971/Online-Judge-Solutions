#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int sum[105][105] ;

int main(){

	int n, x ; 
	scanf("%d", &n);
	
	for(int i = 1 ; i <= n; i++){
		for(int j = 1 ; j <= n ; j++){
			scanf("%d", &sum[i][j]);
			// sum[i][j] = sum of rectangle (1,1) to (i,j)
			sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] ;
		}
	}

	int ans = INT_MIN ;
	
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			// upper left point is (i, j)
			for(int k = i ; k <= n ; k++){
				for(int l = j ; l <= n ; l++){
					// lower right point is (k, l)
					x = sum[k][l] - sum[k][j-1] - sum[i-1][l] + sum[i-1][j-1] ;
					ans = max(ans, x) ;
				}
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}