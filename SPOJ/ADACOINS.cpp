#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 100005 ;
int ar[mx] ;

int main(){

	bitset<mx> bs ;
	bs[0] = 1 ;

	int n, q, x ;
	scanf("%d %d", &n, &q);
	while(n--){
		scanf("%d", &x);
		bs |= (bs << x) ;
	}

	ar[0] = 1 ;
	for(int i = 1 ; i < mx; i++){
		ar[i] += ar[i-1] + bs[i] ;
	}

	int b, e ;
	while(q--){
		scanf("%d %d", &b, &e);
		printf("%d\n", ar[e] - ar[b-1]) ;
	}

	return 0;
}