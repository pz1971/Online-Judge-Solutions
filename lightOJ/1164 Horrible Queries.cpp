#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

#define mid ((lo + hi) >> 1)
#define left (node << 1)
#define right (node << 1) | 1

const int mx = 100005 ;
LL tree[mx * 3], lazy[mx * 3] ; 

void build(int node, int lo, int hi){
	tree[node] = lazy[node] = 0 ;
	if(lo < hi){
		build(left, lo, mid) ;
		build(right, mid + 1, hi) ;
	}
}

void propagate(int node, int lo, int hi){
	tree[node] += lazy[node] * (LL)(hi - lo + 1) ;
	if(lo < hi){
		lazy[left] += lazy[node] ;
		lazy[right] += lazy[node] ;
	}
	lazy[node] = 0 ;
}

void update(const int v, const int l, const int r, int node, int lo, int hi){
	if(lazy[node] != 0)
		propagate(node, lo, hi) ;

	if(hi < l || lo > r){
		return ;
	}
	else if(l <= lo && hi <= r){
		tree[node] += v * (hi - lo + 1) ;
		if(lo < hi){
			lazy[left] += v ;
			lazy[right] += v ;
		}
	}
	else {
		update(v, l, r, left, lo, mid) ;
		update(v, l, r, right, mid + 1, hi) ;
		tree[node] = tree[left] + tree[right] ;
	}
}

LL query(const int l, const int r, int node, int lo, int hi){
	if(lazy[node] != 0)
		propagate(node, lo, hi) ;

	if(hi < l || lo > r){
		return 0LL ;
	}
	else if(l <= lo && hi <= r){
		return tree[node] ;
	}
	else {
		return query(l, r, left, lo, mid)
			+ query(l, r, right, mid + 1, hi) ;
	}
}

int main(){

	int test_case ;
	scanf("%d", &test_case);
	
	int n, q ;
	for(int tc = 1 ; tc <= test_case ; tc++){
		scanf("%d %d", &n, &q);
		
		printf("Case %d:\n", tc) ;
		build(1, 1, n) ;

		int type, x, y, v ;
		while(q--){
			scanf("%d", &type);
			if(type == 0){
				scanf("%d %d %d", &x, &y, &v);
				update(v, x + 1, y + 1, 1, 1, n) ;
			}
			else {
				scanf("%d %d", &x, &y);
				printf("%lld\n", query(x + 1, y + 1, 1, 1, n)) ;
			}
		}
	}

	return 0;
}