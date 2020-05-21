#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int n, m ;
vector<int> g[105] ;
int v[105] ;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int test_cases ;
	cin >> test_cases ;
	
	for(int tc = 1 ; tc <= test_cases ; tc++){
		cin >> n >> m ;
		for(int i = 0 ; i < n ; i++){
			cin >> v[i] ;
			g[i].clear() ;
		}
		int uu, vv; 
		while(m--){
			cin >> uu >> vv ;
			g[uu].push_back(vv) ;
		}
		
		int cur = 0 ;
		int ans = 0 ;

		while(true){
			bool f = 1 ;

			ans += v[cur] ;

			int mx = 0, mu = 0 ;
			for(auto i : g[cur]){
				if(v[i] > mx){
					mx = v[i] ;
					mu = i ;
					f = 0 ;
				}
			}

			if(f){
				cout<< "Case "<< tc<< ": " << ans << " " << cur << endl ;
				break ;
			}
			cur = mu ;
		}
	}

	return 0;
}