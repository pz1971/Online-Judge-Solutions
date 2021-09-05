#include <bits/stdc++.h>
using   namespace  std ;
using LL  =  long long ;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using   namespace __gnu_pbds ;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set ;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset ;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n, m ;

	while(cin >> n >> m){
		ordered_set Set ;
		int ans = 0, x ;

		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= m ; j++){
				cin >> x ;
				if(x == n * m){
					ans = (ans + (n - i) + (m - j)) % 2 ;
				}

				Set.insert(x) ;
				ans = (ans + (x - Set.order_of_key(x) - 1)) % 2 ;
			}
		}

		cout << "YN"[ans] << endl ;
	}

	return 0;
}