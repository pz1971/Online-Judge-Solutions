#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	vector<int> ar(3) ;
	vector<int> ans ;

	while(true){
		for(auto &i : ar)
			cin >> i ;
		sort(ar.begin(), ar.end()) ;
		
		if(ar[0] == ar[2]){	// set
			if(ar[0] == 0)
				break ;

			else if(ar[0] == 13)
				ans.clear() ;
			else 
				ans = {ar[0] + 1, ar[1] + 1, ar[2] + 1} ;
		}
		else if(ar[0] == ar[1] || ar[1] == ar[2]){	// pair
			if(ar[0] == ar[1]){
				if(ar[2] == 13)
					ans = {ar[0] + 1, ar[1] + 1, 1} ;
				else 
					ans = {ar[0], ar[1], ar[2] + 1} ;
			}
			else {
				if(ar[0] + 1 < ar[1]){
					ans = {ar[0] + 1, ar[1], ar[2]} ;
				}
				else {
					if(ar[2] == 13)
						ans = {1, 1, 1} ;
					else 
						ans = {ar[0] + 2, ar[1], ar[2]} ;
				}
			}
		}
		else {	// no pair
			ans = {1, 1, 2} ;
		}

		sort(ans.begin(), ans.end()) ;
		if(ans.empty())
			cout << "*" << endl ;
		else 
			cout << ans[0] << " " << ans[1] << " " << ans[2] << endl ;
	}

	return 0;
}