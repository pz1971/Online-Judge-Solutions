#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 10005 ;
int n ;
LL child_count[mx] ;
vector<int> g[mx] ;

int dfs(int cur){
	child_count[cur] = 0 ;

	for(auto i : g[cur]){
		child_count[cur] += dfs(i) ;
	}

	return child_count[cur] + 1 ;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int test_case ;
	cin >> test_case ;
	
	for(int Forest = 1 ; Forest <= test_case ; Forest++){
		cin >> n ;
		
		int par ;
		for(int i = 1 ; i <= n ; i++){
			g[i].clear() ;
		}

		for(int i = 1 ; i <= n ; i++){
			cin >> par ;
			g[par].push_back(i) ;
		}

		dfs(0) ;

		cout << "Forest#" << Forest << ": " ;
		for(int i = 1 ; i <= n ; i++){
			LL cnt = child_count[i] ;

			const vector<int> &ar = g[i] ;

			for(int j = 0 ; j < ar.size() ; j++){
				for(int k = j + 1 ; k < ar.size() ; k++){
					cnt += (child_count[ar[j]] + 1LL) * (child_count[ar[k]] + 1LL) ;
				}
			}
			cout << cnt << " \n"[i == n] ;
		}
	}

	return 0;
}