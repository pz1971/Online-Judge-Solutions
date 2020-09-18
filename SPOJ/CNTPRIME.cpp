#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

const int _SIEVE_MX = 1000005;
bool stat[_SIEVE_MX];

void sieve(){
	for(int i = 3; i*i < _SIEVE_MX; i += 2){
		if(!stat[i]){
			for(int j = i*i; j < _SIEVE_MX; j += i+i)
				stat[j] = 1;
		}
	}
}

bool isPrime(int n){
	if(n > 1 && n < 4)
		return true;
	if(n % 2 == 0 || n == 1)
		return false;
	return (stat[n] == 0);
}

const int mx = 10005 ;

#define mid ((lo + hi) >> 1)
#define left (cur << 1)
#define right (left | 1)

int ar[mx], tree[mx << 2], lazy[mx << 2] ;

void init(int cur, int lo, int hi){
	lazy[cur] = 0 ;
	if(lo == hi)
		tree[cur] = (int) isPrime(ar[lo]) ;
	else {
		init(left, lo, mid) ;
		init(right, mid + 1, hi) ;
		tree[cur] = tree[left] + tree[right] ;
	}
}

void propagate(int cur, int lo, int hi){
	if(isPrime(lazy[cur]))
		tree[cur] = hi - lo + 1 ;
	else 
		tree[cur] = 0 ;
	
	if(lo < hi){
		lazy[left] = lazy[right] = lazy[cur] ;
	}
	lazy[cur] = 0 ;
}

void update(const int x, const int y, const int v, int cur, int lo, int hi){
	if(lazy[cur] != 0)
		propagate(cur, lo, hi) ;
	if(lo > y || hi < x)
		return ;
	else if (lo >= x && hi <= y){
		lazy[cur] = v ;
		propagate(cur, lo, hi) ;
	}
	else {
		update(x, y, v, left, lo, mid) ;
		update(x, y, v, right, mid + 1, hi) ;
		tree[cur] = tree[left] + tree[right] ;
	}
}

int query(const int x, const int y, int cur, int lo, int hi){
	if(lazy[cur] != 0)
		propagate(cur, lo, hi) ;
	if(lo > y || hi < x)
		return 0 ;
	else if (lo >= x && hi <= y)
		return tree[cur] ;
	else {
		return query(x, y, left, lo, mid)
			+ query(x, y, right, mid + 1, hi) ;
	}
}

int main(){

	sieve() ;
	
	int test_cases ;
	scanf("%d", &test_cases);
	
	for(int tc = 1 ; tc <= test_cases ; tc++){
		int n, q; 
		scanf("%d %d", &n, &q);
		for(int i = 1 ; i <= n ; i++)
			scanf("%d", &ar[i]);
		
		init(1, 1, n) ;
		printf("Case %d:\n", tc) ;

		int type, x, y, v ;
		while(q--){
			scanf("%d", &type);
			if(type == 0){
				scanf("%d %d %d", &x, &y, &v);
				update(x, y, v, 1, 1, n) ;
			}
			else {
				scanf("%d %d", &x, &y);
				printf("%d\n", query(x, y, 1, 1, n)) ;
			}
		}
	}

	return 0;
}