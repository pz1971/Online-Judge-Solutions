#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

const int mod = 1000000007 ;

class BIT{
private:
	int n ;
	vector<int> tree ;
public :
	BIT(int _size){ // constructor
		n = _size ;
		if(n > 0)
			tree = vector<int>(n, 0) ;
	}
	
	~BIT(){	// destructor
		tree.clear() ;
	}

	void add(int pos, int val){	// O(lg(n))
		while(pos <= n){
			tree[pos - 1] = (tree[pos - 1] + val) % mod ;
			pos += pos & (-pos) ;
		}
	}
	int query(int pos){	// O(lg(n))
		int ret = 0 ;
		while(pos > 0){
			ret = (ret + tree[pos - 1]) % mod ;
			pos -= pos & (-pos) ;
		}
		return ret ;
	}
	int query(int l, int r){	// best O(1) avg O(lg(n))
		if(l == r)	return tree[l - 1] ;
		return ((query(r) - query(l - 1)) + mod) % mod ;
	}
} ;

int main(){

	int test_cases ;
	scanf("%d", &test_cases);
	
	for(int tc = 1 ; tc <= test_cases ; tc++){
		int n ;
		cin >> n ;
		
		vector<int> ar(n) ;
		for(int &i : ar)
			scanf("%d", &i);
		
		// convert {123, 4, 62} -> {3, 1, 2}

		vector<int> ar2 = ar ;
		sort(ar2.begin(), ar2.end()) ;
		unordered_map<int, int> id ;
		
		int x = 0 ;
		id[ ar2[0] ] = ++x ;
		for(int i = 1 ; i < n ; i++){
			if(ar2[i] > ar2[i-1])
				id[ ar2[i] ] = ++x ;
		}
		
		BIT tree(x) ; // x = max size
		for(auto &i : ar){
			i = id[i] ;
			
			if(i > 1)
				tree.add(i, tree.query(1, i-1) + 1) ;
			else 
				tree.add(i, 1) ;
		}

		printf("Case %d: %d\n", tc, tree.query(1, x)) ;
	}

	return 0;
}