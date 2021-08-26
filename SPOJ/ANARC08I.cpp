//                    recursive solution
//--------------------------------------

// #include <bits/stdc++.h>
// using   namespace  std ;
// typedef long   long LL ;

// int query(LL n, LL r, LL c){
// 	if(n == 1LL)
// 		return 1 ;
	
// 	n >>= 1 ;

// 	if(r < n && c >= n) // 1st quadrant
// 		return query(n, r, c - n) ;
// 	else if(r < n && c < n) // 2nd quadrant
// 		return query(n, r, c) ;
// 	else if(r >= n && c < n) // 3rd quadrant
// 		return query(n, r - n, c) ;
// 	else 	// 4th quadrant
// 		return -query(n, r - n, c - n) ;
// }

// int main(){

// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0); cout.tie(0);
	
// 	LL n, r, s, e ;
// 	LL n2, r2, c2 ;

// 	while(cin >> n >> r >> s >> e){
// 		if(n == -1 && r == -1 && s == -1 && s == -1)
// 			break ;
		
// 		n = 1LL << n ;
// 		int sum = 0 ;
// 		for(LL i = s ; i <= e ; i++){
// 			sum += query(n, r, i) ;
// 		}
// 		cout << sum << endl ;
// 	}

// 	return 0 ;
// }


//                    iterative solution
//--------------------------------------

#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	LL n, r, s, e ;
	LL n2, r2, c2 ;

	while(cin >> n >> r >> s >> e){
		if(n == -1 && r == -1 && s == -1 && s == -1)
			break ;
		
		if(n == 0){
			cout << 1 << endl ;
			continue ;
		}

		int sum = 0 ;
		while(s <= e){
			n2 = 1LL << (n - 1) ;
			r2 = r ;
			c2 = s++ ;

			int sign = 1 ;
			while(n2){
				if(r2 >= n2 && c2 >= n2)
					sign *= -1 ;
				if(r2 >= n2)	r2 -= n2 ;
				if(c2 >= n2)	c2 -= n2 ;
				n2 >>= 1 ;
			}
			sum += sign ;
		}

		cout << sum << endl ;
	}

	return 0 ;
}
