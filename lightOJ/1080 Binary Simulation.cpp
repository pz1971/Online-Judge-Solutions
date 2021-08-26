#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

#define mid ((lo + hi) >> 1)
#define left (cur << 1)
#define right (left | 1)

const int mx = 1e5 + 5 ;
char num[mx] ;
bool lazy[mx << 2] ;

void init(int cur, int lo, int hi){
	lazy[cur] = 0 ;
	if(lo < hi) {
		init(left, lo, mid) ;
		init(right, mid + 1, hi) ;
	}
}

void invert(const int i, const int j, int cur, int lo, int hi){
	if(lo > j || hi < i)
		return ;
	else if(lo >= i && hi <= j)
		lazy[cur] = ! lazy[cur] ;
	else{
		invert(i, j, left, lo, mid) ;
		invert(i, j, right, mid + 1, hi) ;
	}
}

bool query(const int i, int cur, int lo, int hi){
	bool ret = 0 ;
	
	if(lo == hi){
		ret = (num[i - 1] == '1') ;
	}
	else {
		if(i >= lo && i <= mid)
			ret = query(i, left, lo, mid) ;
		else
			ret = query(i, right, mid + 1, hi) ;
	}

	return lazy[cur] ? (!ret) : ret ;
}

int main(){

	int test_cases ;
	scanf("%d", &test_cases);
	
	for(int tc = 1 ; tc <= test_cases ; tc++){
		scanf("%s", &num) ;
		int n = strlen(num) ;
		
		init(1, 1, n) ;
		
		printf("Case %d:\n", tc) ;
		int q ;
		scanf("%d", &q);

		char type ;
		int i, j ;
		while(q--){
			scanf("%*c%c", &type);
			if(type == 'I'){
				scanf("%d %d", &i, &j);
				invert(i, j, 1, 1, n) ;
			}
			else {
				scanf("%d", &i);
				printf("%d\n", query(i, 1, 1, n)) ;
			}
		}
	}

	return 0;
}