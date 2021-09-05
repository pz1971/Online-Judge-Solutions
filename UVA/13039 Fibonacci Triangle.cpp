#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int main(){

	int t ;
	scanf("%d", &t);

	while(t--){
		int n ;
		scanf("%d", &n);
		int ar[n + 1] ;
		ar[n] = 0 ;
		for(int i = 0 ; i < n ; i++)
			scanf("%d", &ar[i]);
		
		int ans = 0, prev = 0, x ;

		for(int i = 0 ; i < n ; i++){
			x = min(prev, ar[i] / 2) ; // 1, 0, 0, 2
			ans += x ;
			ar[i] -= 2 * x ;
			prev -= x ;

			ans += ar[i] / 3 ; // 3, 3, 3
			ar[i] %= 3 ;
			
			x = min(ar[i] / 2 , ar[i + 1]) ; //2, 1
			ans += x ;
			ar[i] -= 2 * x ;
			ar[i + 1] -= x ;

			prev += ar[i] ;
		}

		printf("%d\n", ans);
	}

	return 0;
}