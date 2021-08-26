#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int test_case ;
	cin >> test_case ;
	
	while(test_case--){
		int n ;
		cin >> n ;

		vector<int> ar(n) ;
		for(auto &i : ar)
			cin >> i ;

		unordered_map<int, int> mp ;
		int from = 0 ;
		LL ans = 0LL ;

		for(int i = 0 ; i < n ; i++){
			if(mp[ar[i]] > from){
				from = mp[ar[i]] ;
			}
			mp[ar[i]] = i + 1 ;
			ans += i + 1 - from ;
		}

		cout << ans << endl ;
	}

	return 0;
}