#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

#define mid ((lo + hi) >> 1)
#define left (cur << 1)
#define right (left | 1)

const int mx = 300005 ;

vector<vector<int> > indx;	// indices of all colors
int ar[mx], tree[mx * 3] ; // tree[i] contains the color that occurred the most in segment i

void init(int cur, int lo, int hi){
	if(lo == hi){
		tree[cur] = ar[lo] ;
	}
	else {
		init(left, lo, mid) ;
		init(right, mid + 1, hi) ;
		
		if(tree[left] == tree[right]){
			tree[cur] = tree[left] ;
			return ;
		}
		
		int col = tree[left] ;
		int col2 = tree[right] ;

		int cnt = upper_bound(indx[col].begin(), indx[col].end(), hi) - lower_bound(indx[col].begin(), indx[col].end(), lo) ;
		int cnt2 = upper_bound(indx[col2].begin(), indx[col2].end(), hi) - lower_bound(indx[col2].begin(), indx[col2].end(), lo) ;

		if(cnt >= cnt2)
			tree[cur] = tree[left] ;
		else 
			tree[cur] = tree[right] ;
	}
}

int query(const int a, const int b, int cur, int lo, int hi){
	if(lo > b || hi < a)
		return 0 ;
	else if(lo >= a and hi <= b)
		return tree[cur] ;
	else {
		int col = query(a, b, left, lo, mid) ;
		int col2 = query(a, b, right, mid + 1, hi) ;
		
		if(col == col2)
			return col ;
		
		int cnt = upper_bound(indx[col].begin(), indx[col].end(), b) - lower_bound(indx[col].begin(), indx[col].end(), a) ;
		int cnt2 = upper_bound(indx[col2].begin(), indx[col2].end(), b) - lower_bound(indx[col2].begin(), indx[col2].end(), a) ;
		
		if(cnt >= cnt2)
			return col ;
		else 
			return col2 ;
	}
}

int main(){

	int n, c ;
	scanf("%d %d", &n, &c);
	
	indx = vector<vector<int> > (c + 1, vector<int> ()) ;
	for(int i = 1 ; i <= n ; i++){
		scanf("%d", &ar[i]);
		indx[ ar[i] ].push_back( i ) ;
	}

	init(1, 1, n) ;

	int m, a, b ;
	scanf("%d", &m);

	while(m--){
		scanf("%d %d", &a, &b);
		
		int col = query(a, b, 1, 1, n) ;
		int cnt = upper_bound(indx[col].begin(), indx[col].end(), b) - lower_bound(indx[col].begin(), indx[col].end(), a) ;

		if(cnt * 2 > (b - a + 1)){
			printf("yes %d\n", col) ;
		}
		else {
			printf("no\n") ;
		}
	}

	return 0;
}

// #include <bits/stdc++.h>
// using   namespace  std ;
// using LL  =  long long ;

// #define mid ((lo + hi) >> 1)
// #define left (cur << 1)
// #define right (left | 1)

// const int mx = 300005 ;

// vector<vector<int> > indx;	// indices of all colors
// int ar[mx], tree[mx * 3] ; // tree[i] contains the color that occurred the most in segment i

// int merge(int col, int col2, int lo, int hi){
// 	if(col != -1){
// 		int cnt = upper_bound(indx[col].begin(), indx[col].end(), hi) - lower_bound(indx[col].begin(), indx[col].end(), lo) ;
// 		if(cnt * 2 > (hi - lo + 1))
// 			return col ;
// 	}
// 	if(col2 != -1){
// 		int cnt = upper_bound(indx[col2].begin(), indx[col2].end(), hi) - lower_bound(indx[col2].begin(), indx[col2].end(), lo) ;
// 		if(cnt * 2 > (hi - lo + 1))
// 			return col2 ;
// 	}
// 	return -1 ;
// }

// void init(int cur, int lo, int hi){
// 	if(lo == hi){
// 		tree[cur] = ar[lo] ;
// 	}
// 	else {
// 		init(left, lo, mid) ;
// 		init(right, mid + 1, hi) ;
// 		tree[cur] = merge(tree[left], tree[right], lo, hi) ;
// 	}
// }

// int query(const int a, const int b, int cur, int lo, int hi){
// 	if(lo > b || hi < a)
// 		return -1 ;
// 	else if(lo >= a && hi <= b)
// 		return tree[cur] ;
// 	else {
// 		int col = query(a, b, left, lo, mid) ;
// 		int col2 = query(a, b, right, mid + 1, hi) ;
// 		return merge(col, col2, a, b) ;
// 	}
// }

// int main(){

// 	int n, c ;
// 	scanf("%d %d", &n, &c);
	
// 	indx = vector<vector<int> > (c + 1, vector<int> ()) ;
// 	for(int i = 1 ; i <= n ; i++){
// 		scanf("%d", &ar[i]);
// 		indx[ ar[i] ].push_back( i ) ;
// 	}

// 	init(1, 1, n) ;

// 	int m, a, b ;
// 	scanf("%d", &m);

// 	while(m--){
// 		scanf("%d %d", &a, &b);
// 		int col = query(a, b, 1, 1, n) ;

// 		if(col == -1)
// 			printf("no\n") ;
// 		else 
// 			printf("yes %d\n", col) ;
// 	}

// 	return 0;
// }