#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n, m, x ;
	map<int,bool> mp ;

	while(cin >> n >> m){
		if(!(n || m))
			break ;
		mp.clear() ;
		int cnt = 0 ;

		while(n--){
			cin >> x ;
			mp[x]++ ;
		}
		while(m--){
			cin >> x ;
			if(mp[x])
				cnt++ ;
		}
		cout << cnt << endl ;
	}

	return 0;
}