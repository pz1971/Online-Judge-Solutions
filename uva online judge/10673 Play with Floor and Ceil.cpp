#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

LL func(LL x, LL k, LL p, LL q){
	LL ret = p * (x / k) ;
	if(x % k == 0)
		return (ret + q * (x / k)) ;
	return ret + q * ((x / k) + 1) ;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t ;
	cin >> t ;

	while(t--){
		LL x, k ;
		cin >> x >> k ;

		if(x < k){
			cout << 0 << " " << x << endl ;	// floor(x/k) is always 0, ceil(x/k) is always 1 ;
		}
		else{
			LL l = 0, u = k , mid ;	// p == mid , q == k - mid
			LL val ;
			while(l <= u){
				mid = (l + u) >> 1 ;
				val = func(x, k, mid, k - mid) ;
				
				if(x == val)
					break ;
				else if(x > val)
					u = mid - 1 ;
				else
					l = mid + 1 ;
			}
			cout << mid << " " << (k - mid) << endl ;
		}
	}

	return 0;
}