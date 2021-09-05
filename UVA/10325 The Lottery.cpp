#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

LL LCM(LL a, LL b){
	return (a * b) / __gcd(a, b) ;
}

LL n, m, ar[16], ans ;

void DFS(LL sign, LL cur, int idx){
	if(idx == m){
		ans += sign * (n / cur) ;
	}
	else if(cur <= n){
		DFS(sign, cur, idx+1) ;
		DFS(0LL - sign, LCM(cur, ar[idx]) , idx+1) ;
	}
}

int main(){
	
	while(scanf("%lld %lld", &n, &m) != EOF){
		for(int i = 0 ; i < m ; i++)
			scanf("%lld", &ar[i]);
		
		ans = 0 ;
		DFS(1, 1, 0) ;

		printf("%lld\n", ans) ;
	}

	return 0;
}