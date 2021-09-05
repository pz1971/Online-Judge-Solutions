#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

int n, q ;
int fenwick_tree[100005] ;

void add(int p, int v){
	while(p <= n){
		fenwick_tree[p] += v ;
		p += p & (-p) ;
	}
}

int query(int p){
	int ret = 0 ;
	while(p > 0){
		ret += fenwick_tree[p] ;
		p -= p & (-p) ;
	}
	return ret ;
}

int main(){

	int test_cases ;
	scanf("%d", &test_cases);
	
	for(int tc = 1 ; tc <= test_cases ; tc++){
		scanf("%d %d", &n, &q);

		for(int i = 0 ; i <= n ; i++)
			fenwick_tree[i] = 0 ;
		
		int v ;
		for(int i = 1 ; i <= n ; i++){
			scanf("%d", &v);
			add(i, v) ;
		}

		printf("Case %d:\n", tc) ;
		
		int type, i, j ;
		while(q--){
			scanf("%d", &type);
			if(type == 1){
				scanf("%d", &i);
				++i ;
				v = query(i) - query(i - 1) ;
				printf("%d\n", v) ;
				add(i, -v) ;
			}
			else if(type == 2){
				scanf("%d %d", &i, &v);
				add(++i, v) ;
			}
			else {
				scanf("%d %d", &i, &j);
				++i ; ++j ;
				v = query(j) - query(i - 1) ;
				printf("%d\n", v) ;
			}
		}
	}

	return 0;
}