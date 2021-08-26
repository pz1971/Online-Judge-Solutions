#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

#define mid ((lo + hi) >> 1)
#define left (cur << 1)
#define right (left | 1)

const int mx = 1e5 + 5 ;

int ar[mx] ;
int tree[mx << 2] ;

void init(int cur, int lo, int hi){
	if(lo == hi)
		tree[cur] = (ar[lo] == 0 ? 0 : (ar[lo] < 0 ? -1 : 1)) ; 
	else {
		init(left, lo, mid) ;
		init(right, mid + 1, hi) ;
		tree[cur] = tree[left] * tree[right] ;
	}
}

void update(const int i, const int v, int cur, int lo, int hi){
	if(i > hi || i < lo)
		return ;
	if(lo == hi)
		tree[cur] = v ;
	else{
		update(i, v, left, lo, mid) ;
		update(i, v, right, mid + 1, hi) ;
		tree[cur] = tree[left] * tree[right] ;
	}
}

int query(const int i, const int j, int cur, int lo, int hi){
	if(lo > j || hi < i)
		return 1 ;
	else if(lo >= i && hi <= j)
		return tree[cur] ;
	else 
		return query(i, j, left, lo, mid) * query(i, j, right, mid + 1, hi) ;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n, k ;
	while(cin >> n >> k){
		for(int i = 1 ; i <= n ; i++)
			cin >> ar[i] ;
		init(1, 1, n) ;

		string type ;
		int i, j, v ;
		while(k--){

			cin >> type ;
			if(type == "C"){
				cin >> i >> v ;

				v = (v == 0 ? 0 : (v < 0 ? -1 : 1)) ;
				update(i, v, 1, 1, n) ;
			}
			else {
				cin >> i >> j ;
				int a = query(i, j, 1, 1, n) ;
				cout << (a == 0 ? '0' : (a < 0 ? '-' : '+')) ;
			}
		}

		cout << "\n" ;
	}

	return 0;
}