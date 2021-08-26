#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int main(){

	int s ;
	scanf("%d", &s);

	for(int tc = 1 ; tc <= s ; tc++){
		int x ;
		bool f = true ;
		for(int i = 0 ; i < 13 ; i++){
			scanf("%d", &x);
			f &= (bool) x ;
		}
		printf("Set #%d: %s\n", tc, f ? "Yes" : "No");
	}

	return 0;
}