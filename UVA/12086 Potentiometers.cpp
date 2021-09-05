#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

const int mx = 200005 ;

LL ar[mx] ;

class BIT{
private:
	int n ;
	vector<LL> tree ;
public :
	BIT(int _size){ // constructor
		n = _size ;
		if(n > 0)
			tree = vector<LL>(n, 0) ;
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
	LL query(int pos){	// O(lg(n))
		LL ret = 0 ;
		while(pos > 0){
			ret += tree[pos - 1] ;
			pos -= pos & (-pos) ;
		}
		return ret ;
	}
	LL query(int l, int r){	// best O(1) avg O(lg(n))
		if(l == r)	return tree[l - 1] ;
		return (query(r) - query(l - 1)) ;
	}
} ;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int tc = 0 ;
    int n ;
    
	while(cin >> n && n){
		BIT my_tree(n) ;
		for(int i = 0 ; i < n ; i++){
			cin >> ar[i] ;
		}
		my_tree.init(ar) ;

		if(tc)	cout << endl ;
		cout<< "Case "<< ++tc << ":" << endl ;

		string type ;
		int x, y, r ;
		while(cin >> type && type != "END"){
			if(type == "S"){
				cin >> x >> r ;
				my_tree.add(x, r - ar[x - 1]) ;
				ar[x - 1] = r ;
			}
			else{
				cin >> x >> y ;
				cout << my_tree.query(x, y) << endl ;
			}
		}
	}

	return 0;
}



// #include <bits/stdc++.h>
// using   namespace  std ;
// using LL  =  long long ;

// const int mx = 200005 ;

// int n ;
// LL ar[mx], fenwick[mx] ;

// void init(){
// 	for(int i = 1 ; i <= n ; i++){
// 		fenwick[i] += ar[i] ;
// 		if(i + (i & (-i)) <= n)
// 			fenwick[ i + (i & (-i)) ] += fenwick[i] ;
// 	}
// }

// void add(int p, int v){
// 	while(p <= n){
// 		fenwick[p] += v ;
// 		p += p & (-p) ;
// 	}
// }

// LL query(int p){
// 	LL ret = 0LL ;
// 	while(p > 0){
// 		ret += fenwick[p] ;
// 		p -= p & (-p) ;
// 	}
// 	return ret ;
// }

// LL query(int l, int r){
// 	if(l == r)	return ar[l] ;
// 	return query(r) - query(l - 1) ;
// }

// int main(){

// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0); cout.tie(0);
	
// 	int tc = 0 ;

// 	while(cin >> n && n){
// 		for(int i = 1 ; i <= n ; i++){
// 			cin >> ar[i] ;
// 			fenwick[i] = 0 ;
// 		}
// 		init() ;

// 		if(tc)	cout << endl ;
// 		cout<< "Case "<< ++tc << ":" << endl ;

// 		string type ;
// 		int x, y, r ;
// 		while(cin >> type && type != "END"){
// 			if(type == "S"){
// 				cin >> x >> r ;
// 				add(x, r - ar[x]) ;
// 				ar[x] = r ;
// 			}
// 			else{
// 				cin >> x >> y ;
// 				cout << query(x, y) << endl ;
// 			}
// 		}
// 	}

// 	return 0;
// }