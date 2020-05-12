#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using   namespace __gnu_pbds ;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set ;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset ;


int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	ordered_set set ;

	int q ;
	cin >> q ;

	string type ;
	int n ;

	while(q--){
		cin >> type >> n ;
		
		if(type == "I"){
			set.insert(n) ;
		}
		else if(type == "D"){
			auto itr = set.lower_bound(n) ;
			if(itr != set.end() && *itr == n)
				set.erase(itr) ;
		}
		else if(type == "K"){
			n-- ;
			if(n >= set.size())
				cout << "invalid" << endl ;
			else 
				cout << *(set.find_by_order(n)) << endl ;
		}
		else{
			cout << set.order_of_key(n) << endl ;
		}
	}

	return 0;
}