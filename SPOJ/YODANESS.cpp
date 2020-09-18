#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

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

	template<typename T>	// ar[] or std::vector<> of size = n
	void init(const T ar){	// O(n)
		for(int i = 1 ; i <= n ; i++){
			tree[i-1] += ar[i-1] ;
			if(i + (i & (-i)) <= n)
				tree[i + (i & (-i)) - 1] += tree[i-1] ;
		}
	}

	void add(int pos, int val){	// O(lg(n))
		while(pos <= n){
			tree[pos - 1] += val ;
			pos += pos & (-pos) ;
		}
	}
	int query(int pos){	// O(lg(n))
		int ret = 0 ;
		while(pos > 0){
			ret += tree[pos - 1] ;
			pos -= pos & (-pos) ;
		}
		return ret ;
	}
	int query(int l, int r){	// best O(1) avg O(lg(n))
		if(l == r)	return tree[l - 1] ;
		return (query(r) - query(l - 1)) ;
	}
} ;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int test_cases ;
	cin >> test_cases ;
	
	for(int tc = 1 ; tc <= test_cases ; tc++){
		int n ;
		cin >> n ;
		string ar[n] ;
		for(int i = 0 ; i < n ; i++)
			cin >> ar[i] ;
		
		map<string, int> mp ;
		string word ;
		for(int i = 1 ; i <= n ; i++){
			cin >> word ;
			mp[word] = i ;
		}

		BIT my_tree(n) ;
		int total = 0, a, b ;
		for(int i = 0 ; i < n ; i++){
			a = mp[ ar[i] ] ;
			my_tree.add(a, 1) ;
			b = my_tree.query(a) ;
			total += a - b ;
		}
		cout << total << endl ;
	}

	return 0;
}


//---------------- using c++ pbds ----------------//

// #include <bits/stdc++.h>
// using   namespace  std ;
// using LL  =  long long ;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/detail/standard_policies.hpp>
// using   namespace __gnu_pbds ;
// typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set ;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset ;


// int main(){

// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0); cout.tie(0);
	
// 	int test_cases ;
// 	cin >> test_cases ;
	
// 	for(int tc = 1 ; tc <= test_cases ; tc++){
// 		int n ;
// 		cin >> n ;
// 		string ar[n] ;
// 		for(int i = 0 ; i < n ; i++)
// 			cin >> ar[i] ;
		
// 		map<string, int> mp ;
// 		string word ;
// 		for(int i = 1 ; i <= n ; i++){
// 			cin >> word ;
// 			mp[word] = i ;
// 		}

// 		ordered_set st ;

// 		int total = 0, a, b ;
// 		for(int i = 0 ; i < n ; i++){
// 			a = mp[ ar[i] ] ;
// 			st.insert(a) ;
// 			b = st.order_of_key(a) ;

// 			total += (a - 1) - b ;
// 		}
// 		cout << total << endl ;
// 	}

// 	return 0;
// }