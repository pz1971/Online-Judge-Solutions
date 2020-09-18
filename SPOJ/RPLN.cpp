#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

#define mid ((lo + hi) >> 1)
#define left (cur << 1)
#define right (left | 1)

const int mx = 100005 ;
int ar[mx], tree[mx << 2] ;

void build(int cur, int lo, int hi){
	if(lo == hi)
		tree[cur] = ar[lo] ;
	else {
		build(left, lo, mid) ;
		build(right, mid + 1, hi) ;
		tree[cur] = min(tree[left], tree[right]) ;
	}
}

int query(const int a, const int b, int cur, int lo, int hi){
	if(lo > b || hi < a)
		return INT_MAX ;
	else if(lo >= a && hi <= b)
		return tree[cur] ;
	else
		return min(query(a, b, left, lo, mid), query(a, b, right, mid + 1, hi)) ;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int test_cases ;
	cin >> test_cases ;
	
	for(int tc = 1 ; tc <= test_cases ; tc++){
		int n, q ;
		cin >> n >> q ;

		for(int i = 1 ; i <= n ; i++)
			cin >> ar[i] ;
		build(1, 1, n) ;

		cout << "Scenario #" << tc << ":\n" ;
		int a, b ;
		while(q--){
			cin >> a >> b ;
			cout << query(a, b, 1, 1, n) << "\n" ;
		}
	}

	return 0;
}