#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int main(){

	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;

		LL cnt = 0 ;
		unordered_map<int, int> mp ;
		mp[0] = 1 ;
		
		int a, sum = 0 ;
		while(n--){
			cin >> a ;
			sum += a ;
			cnt += mp[sum] ;
			mp[sum]++ ;
		}

		cout << cnt << endl ;
	}

	return 0;
}