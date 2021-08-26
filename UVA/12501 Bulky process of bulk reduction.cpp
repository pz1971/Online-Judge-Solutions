#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

#define mid ((lo + hi) >> 1)
#define left (cur << 1)
#define right (left | 1)

const int mx = 1e5+5 ;

class node {
public:
	LL cost, sum, lazy ;
} tree[mx * 3] ;

void build(int cur, int lo, int hi){
	tree[cur].lazy = 0 ;
	if(lo == hi){
		tree[cur].cost = (100 * lo) ;
		tree[cur].sum = 100 ;
	}
	else{
		build(left, lo, mid) ;
		build(right, mid + 1, hi) ;
		tree[cur].cost = tree[left].cost + tree[right].cost ;
		tree[cur].sum = tree[left].sum + tree[right].sum ;
	}
}

void propagate(int cur, int lo, int hi){
	LL len = hi - lo + 1 ;
	tree[cur].cost += (((hi + lo) * len) >> 1) * tree[cur].lazy ;
	tree[cur].sum += len * tree[cur].lazy ;

	if(lo < hi){
		tree[left].lazy += tree[cur].lazy ;
		tree[right].lazy += tree[cur].lazy ;
	}
	tree[cur].lazy = 0 ;
}

void update(const int i, const int j, const int v, int cur, int lo, int hi){
	if(tree[cur].lazy != 0)
		propagate(cur, lo, hi) ;
	if(hi < i || lo > j)
		return ;
	else if(i <= lo && hi <= j){
		tree[cur].lazy += v ;
		propagate(cur, lo, hi) ;	/* this is necessary. because parent of "cur"
				will be updated depending on "cur" values. */
	}
	else {
		update(i, j, v, left, lo, mid) ;
		update(i, j, v, right, mid + 1, hi) ;
		tree[cur].cost = tree[left].cost + tree[right].cost ;
		tree[cur].sum = tree[left].sum + tree[right].sum ;
	}
}

pair<LL, LL> query(const int i, const int j, int cur, int lo, int hi){
	if(tree[cur].lazy != 0)
		propagate(cur, lo, hi) ;
	if(hi < i || lo > j)
		return make_pair(0LL, 0LL) ;
	else if(i <= lo && hi <= j){
		return make_pair(tree[cur].cost, tree[cur].sum) ;
	}
	else {
		pair<LL, LL> p = query(i, j, left, lo, mid) ;
		pair<LL, LL> p2 = query(i, j, right, mid + 1, hi) ;
		return make_pair(p.first + p2.first, p.second + p2.second) ;
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int test_cases ;
	cin >> test_cases ;
	
	for(int tc = 1 ; tc <= test_cases ; tc++){
		int n, q ;
		cin >> n >> q ;
		build(1, 1, n) ;

		cout<< "Case "<< tc<< ":" << endl ;

		string type ;
		LL i, j, u ;
		
		while (q--){
			cin >> type ;
			if(type == "change"){
				cin >> i >> j >> u ;
				update(i, j, u, 1, 1, n) ;
			}
			else {
				cin >> i >> j ;
				pair<LL, LL> P = query(i, j, 1, 1, n) ;
				cout << P.first - (P.second * (i - 1LL)) << endl ;
			}
		}
	}

	return 0;
}