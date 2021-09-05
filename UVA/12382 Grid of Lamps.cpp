#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int test_cases ;
	cin >> test_cases ;
	
	for(int tc = 1 ; tc <= test_cases ; tc++){
		int m, n; 
		cin >> m >> n ;
		
		vector<int> a(m), b(n) ;
		for(auto &i : a)	cin >> i ;
		for(auto &i : b)	cin >> i ;
		sort(a.begin(), a.end(), greater<int>()) ;
		sort(b.begin(), b.end(), greater<int>()) ;

		int cnt = 0 ;
		for(int i = 0 ; i < m ; i++){
			for(int j = 0 ; j < n ; j++){
				if(a[i] == 0 || b[j] == 0)
					break ;
				a[i]-- ;
				b[j]-- ;
				cnt++ ;
			}
			sort(b.begin(), b.end(), greater<int>()) ;
		}

		for(auto i : a)	cnt += i ;
		for(auto i : b)	cnt += i ;

		cout << cnt << endl ;
	}

	return 0;
}