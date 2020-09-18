#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

#define mid ((lo + hi) >> 1)
#define left (cur << 1)
#define right (left | 1)

const int mx = 1e5 + 5 ;

int tree[mx << 2] ;
bool lazy[mx << 2] ;

void propagate(int cur, int lo, int hi){
	tree[cur] = (hi - lo + 1) - tree[cur] ;
	lazy[cur] = 0 ;
	if(lo < hi){
		lazy[left] = !lazy[left] ;
		lazy[right] = !lazy[right] ;
	}
}

void update(const int s, const int e, int cur, int lo, int hi){
	if(lazy[cur])
		propagate(cur, lo, hi) ;
	
	if(lo > e || hi < s)
		return ;
	else if(lo >= s && hi <= e){
		lazy[cur] = 1 ;
		propagate(cur, lo, hi) ;
	}
	else{
		update(s, e, left, lo, mid) ;
		update(s, e, right, mid + 1, hi) ;
		tree[cur] = tree[left] + tree[right] ;
	}
}

int query(const int s, const int e, int cur, int lo, int hi){
	if(lazy[cur])
		propagate(cur, lo, hi) ;
	
	if(lo > e || hi < s)
		return 0 ;
	else if(lo >= s && hi <= e){
		return tree[cur] ;
	}
	else{
		return query(s, e, left, lo, mid)
			+ query(s, e, right, mid + 1, hi) ;
	}
}

int main(){

	int n, m ;
	scanf("%d %d", &n, &m);

	int q, s, e ;
	while(m--){
		scanf("%d %d %d", &q, &s, &e);
		if(q == 0)
			update(s, e, 1, 1, n) ;
		else 
			printf("%d\n", query(s, e, 1, 1, n)) ;
	}

	return 0;
}