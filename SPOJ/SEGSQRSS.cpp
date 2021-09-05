#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

#define mid ((lo + hi) >> 1)
#define left (cur << 1)
#define right (left | 1)

const int mx = 100005 ;

class node{
public: 
	LL val, sum ;
	pair<int, LL> lazy ; // type, val
} tree[mx * 3] ;

LL ar[mx] ;

void init(int cur, int lo, int hi){
	tree[cur].lazy.first = -1 ;

	if(lo == hi){
		tree[cur].val = (ar[lo] * ar[lo]) ;
		tree[cur].sum = ar[lo] ;
	}
	else {
		init(left, lo, mid) ;
		init(right, mid + 1, hi) ;

		tree[cur].val = tree[left].val + tree[right].val ;
		tree[cur].sum = tree[left].sum + tree[right].sum ;
	}
}

void propagate(int cur, int lo, int hi){
	LL len = hi - lo + 1 ;
	LL x = tree[cur].lazy.second ;
	
	if(tree[cur].lazy.first == 0){
		tree[cur].val = len * x * x ;
		tree[cur].sum = len * x ;
	}
	else{
		// a^2+b^2+c^2 -> add x -> (a+x)^2+(b+x)^2+(c+x)^2
		// tree[cur].val += diff ;

		tree[cur].val += len * x * x + 2LL * x * tree[cur].sum ;
		tree[cur].sum += len * x ;
	}

	if(lo < hi){
		tree[left].lazy = tree[cur].lazy ;
		tree[right].lazy = tree[cur].lazy ;
	}
	tree[cur].lazy.first = -1 ;
}

void update(const int f, const int l, const int r, const LL x, int cur, int lo, int hi){
	if(tree[cur].lazy.first != -1)
		propagate(cur, lo, hi) ;

	if(lo > r || hi < l)
		return ;
	else if(lo >= l && hi <= r){
		tree[cur].lazy = {f, x} ;
		propagate(cur, lo, hi) ;
	}
	else {
		update(f, l, r, x, left, lo, mid) ;
		update(f, l, r, x, right, mid + 1, hi) ;

		tree[cur].val = tree[left].val + tree[right].val ;
		tree[cur].sum = tree[left].sum + tree[right].sum ;
	}
}

LL query(const int l, const int r, int cur, int lo, int hi) {
	if(tree[cur].lazy.first != -1)
		propagate(cur, lo, hi) ;
	
	if(lo > r || hi < l)
		return 0LL ;
	else if(lo >= l && hi <= r)
		return tree[cur].val ;
	else 
		return query(l, r, left, lo, mid) + query(l, r, right, mid + 1, hi) ;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int test_cases ;
	cin >> test_cases ;
	
	for(int tc = 1 ; tc <= test_cases ; tc++){
		int n, q ;
		cin >> n >> q ;

		for(int i = 1; i <= n ; i++)
			cin >> ar[i] ;
		init(1, 1, n) ;

		cout<< "Case "<< tc<< ":" << endl ;
		
		int type, st, nd, x ;
		while(q--){
			cin >> type ;
			if(type == 0){
				cin >> st >> nd >> x ;
				update(0, st, nd, x, 1, 1, n) ;
			}
			else if(type == 1){
				cin >> st >> nd >> x ;
				update(1, st, nd, x, 1, 1, n) ;
			}
			else {
				cin >> st >> nd ;
				cout << query(st, nd, 1, 1, n) << endl ;
			}
		}
	}

	return 0;
}