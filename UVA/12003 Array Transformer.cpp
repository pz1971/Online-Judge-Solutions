#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using   namespace __gnu_pbds ;
typedef tree<LL, null_type,less<LL>, rb_tree_tag,tree_order_statistics_node_update> ordered_set ;
typedef tree<LL, null_type, less_equal<LL>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset ;

const int mx = 300005 ;

int n, m ;
LL u ;
LL ar[mx] ;
ordered_multiset segment_tree[mx * 4] ;

void build(int node, int lo, int hi){
	if(lo == hi){
		segment_tree[node].insert(ar[lo]) ;
		return ;
	}

	int mid = (lo + hi) >> 1 ;
	int left = (node << 1) ;
	int right = (left | 1) ;

	build(left, lo, mid) ;
	build(right, mid + 1, hi) ;

	for(auto i : segment_tree[left])
		segment_tree[node].insert(i) ;
	for(auto i : segment_tree[right])
		segment_tree[node].insert(i) ;
}

int query(const LL v, const int l, const int r, int node, int lo, int hi){
	if(lo > r || hi < l)
		return 0 ;
	if(l <= lo && r >= hi)
		return segment_tree[node].order_of_key(v) ;

	int mid = (lo + hi) >> 1 ;
	int left = (node << 1) ;
	int right = (left | 1) ;

	return query(v, l, r, left, lo, mid) + query(v, l, r, right, mid+1, hi) ;
}

void update(const LL key, const int pos, int node, int lo, int hi){
	if(pos < lo || pos > hi)
		return ;
	if(lo == hi && lo == pos){
		segment_tree[node].clear() ;
		segment_tree[node].insert(key) ;
		return ;
	}
	
	segment_tree[node].erase(segment_tree[node].upper_bound(ar[pos])) ;
	segment_tree[node].insert(key) ;
	
	int mid = (lo + hi) >> 1 ;
	int left = (node << 1) ;
	int right = (left | 1) ;

	update(key, pos, left, lo, mid) ;
	update(key, pos, right, mid + 1, hi) ;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> u ;
	for(int i = 1 ; i <= n ; i++)
		cin >> ar[i] ;
	
	build(1, 1, n) ;

	while(m--){
		int l, r, p ;
		LL v ;
		cin >> l >> r >> v >> p ;

		LL k = query(v, l, r, 1, 1, n) ;
		k = (u * k) / (r - l + 1LL) ;
		
		update(k, p, 1, 1, n) ;
		ar[p] = k ;
	}

	for(int i = 1 ; i <= n ; i++)
		cout << ar[i] << endl ;

	return 0;
}