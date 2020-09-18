#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using   namespace __gnu_pbds ;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set ;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset ;

const int mx = 30005 ;

#define mid ((lo + hi) >> 1)
#define left (cur << 1)
#define right (left | 1)

int ar[mx] ;
ordered_multiset segment[mx * 3] ;

void init(int cur, int lo, int hi){
	segment[cur].clear() ;

	for(int i = lo; i <= hi ; i++)
		segment[cur].insert( -ar[i] ) ;
	
	if(lo < hi){
		init(left, lo, mid) ;
		init(right, mid + 1, hi) ;
	}
}

int query(const int i, const int j, const int k, int cur, int lo, int hi){
	if(lo > j || hi < i)
		return 0 ;
	else if(lo >= i && hi <= j)
		return segment[cur].order_of_key( -k ) ;
	else
		return query(i, j, k, left, lo, mid) + query(i, j, k, right, mid + 1, hi) ;
}

int main(){

	int n ;

	while(scanf("%d", &n) != EOF){
		for(int i = 1 ; i <= n ; i++)
			scanf("%d", &ar[i]);
		init(1, 1, n) ;

		int q, i, j, k ;
		scanf("%d", &q);

		while(q--){
			scanf("%d %d %d", &i, &j, &k);
			printf("%d\n", query(i, j, k, 1, 1, n)) ;
		}
	}

	return 0;
}