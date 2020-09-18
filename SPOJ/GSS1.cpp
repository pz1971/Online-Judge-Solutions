#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

#define mid ((lo + hi) >> 1)
#define left (cur << 1)
#define right (left | 1)

const int _MX = 50005 ;

class node{
public:
	LL sum, pre_sum, suf_sum, mx_sum ;
} tree[_MX << 2] ;

LL ar[_MX] ;

node merge(const node &b, const node &c){	// a = b + c
	node a ;
	a.sum = b.sum + c.sum ;
	a.pre_sum = max(b.pre_sum, b.sum + c.pre_sum) ;
	a.suf_sum = max(c.suf_sum, c.sum + b.suf_sum) ;
	a.mx_sum = max(max(b.mx_sum, c.mx_sum), b.suf_sum + c.pre_sum) ;
	return a ;
}

void init(int cur, int lo, int hi){
	if(lo == hi){
		tree[cur].sum = tree[cur].mx_sum = ar[lo] ;
		tree[cur].pre_sum = tree[cur].suf_sum = ar[lo] ;
	}
	else{
		init(left, lo, mid) ;
		init(right, mid + 1, hi) ;
		tree[cur] = merge(tree[left], tree[right]) ;
	}
}

vector<int> pos ;
void query(const int x, const int y, int cur, int lo, int hi){
	if(lo > y || hi < x)
		return ;
	else if(lo >= x && hi <= y)
		pos.push_back(cur) ;
	else {
		query(x, y, left, lo, mid) ;
		query(x, y, right, mid + 1, hi) ;
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n ;
	cin >> n ;
	for(int i = 1; i <= n ; i++)
		cin >> ar[i] ;
	
	init(1, 1, n) ;

	int m, x, y ;
	cin >> m ;
	while(m--){
		cin >> x >> y ;
		pos.clear() ;
		query(x, y, 1, 1, n) ;

		node res = tree[pos[0]] ;
		for(int i = 1 ; i < pos.size() ; i++)
			res = merge(res, tree[pos[i]]) ;
		cout << res.mx_sum << endl ;
	}

	return 0;
}