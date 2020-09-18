#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

#define mid ((lo + hi) >> 1)
#define left (cur << 1)
#define right (left | 1)

const int mx = 1024005 ;
string s ;
// tree[i] contains number of 1s
// lazy[i] = -1 if nothing to do, 2 if needs to invert else {0, 1} that needs to be assigned
int tree[mx * 3], lazy[mx * 3] ;

void build(int cur, int lo, int hi){
	lazy[cur] = -1 ;

	if(lo == hi){
		if(s[lo - 1] == '0')
			tree[cur] = 0 ;
		else 
			tree[cur] = 1 ;
	}
	else {
		build(left, lo, mid) ;
		build(right, mid + 1, hi) ;
		tree[cur] = tree[left] + tree[right] ;
	}
}

void propagate(int cur, int lo, int hi){
	if(lazy[cur] == 0)
		tree[cur] = 0 ;
	else if(lazy[cur] == 1)
		tree[cur] = (hi - lo + 1) ;
	else // lazy[cur] == 2
		tree[cur] = (hi - lo + 1) - tree[cur] ;
	
	if(lo < hi){
		if(lazy[cur] != 2){
			lazy[left] = lazy[right] = lazy[cur] ;
		}
		else{
			if(lazy[left] == -1)
				lazy[left] = 2 ;
			else if(lazy[left] == 2)
				lazy[left] = -1 ;
			else if(lazy[left] == 0)
				lazy[left] = 1 ;
			else // lazy[left] == 1
				lazy[left] = 0 ;
			
			if(lazy[right] == -1)
				lazy[right] = 2 ;
			else if(lazy[right] == 2)
				lazy[right] = -1 ;
			else if(lazy[right] == 0)
				lazy[right] = 1 ;
			else // lazy[right] == 1
				lazy[right] = 0 ;
		}
	}

	lazy[cur] = -1 ;
}

void update(const int v, const int a, const int b, int cur, int lo, int hi){
	if(lazy[cur] != -1)
		propagate(cur, lo, hi) ;
	
	if(lo > b || hi < a)
		return ;
	else if(lo >= a && hi <= b){
		lazy[cur] = v ;
		propagate(cur, lo, hi) ;
	}
	else {
		update(v, a, b, left, lo, mid) ;
		update(v, a, b, right, mid + 1, hi) ;
		tree[cur] = tree[left] + tree[right] ;
	}
}

int query(const int a, const int b, int cur, int lo, int hi){
	if(lazy[cur] != -1)
		propagate(cur, lo, hi) ;
	
	if(lo > b || hi < a)
		return 0 ;
	else if(lo >= a && hi <= b)
		return tree[cur] ;
	else 
		return (query(a, b, left, lo, mid) + query(a, b, right, mid + 1, hi)) ;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int test_cases ;
	cin >> test_cases ;
	
	for(int tc = 1 ; tc <= test_cases ; tc++){
		s.clear() ;

		int m, times ;
		string str ;
		cin >> m ;
		while(m--){
			cin >> times >> str ;
			while(times--){
				s.append(str) ;
			}
		}
		
		int n = s.size() ;
		build(1, 1, n) ;
		cout<< "Case "<< tc<< ":" << endl ;

		int q ;
		cin >> q ;
		int quer = 0 ;
		
		string type; 
		int a, b ;
		while(q--){
			cin >> type >> a >> b ;
			++a ; b++ ;
			if(type == "S")
				cout << "Q" << ++quer << ": " << query(a, b, 1, 1, n) << endl ;
			else {
				if(type == "F")
					update(1, a, b, 1, 1, n) ;
				else if(type == "E")
					update(0, a, b, 1, 1, n) ;
				else // "I"
					update(2, a, b, 1, 1, n) ;
			}
		}
	}

	return 0;
}